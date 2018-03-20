#include "mdefs.h"
#include <iostream>
#include <fstream>
#include <Copter/InterpolatedPS.h>
#include <Copter/Cosmology.h>
#include <Copter/Quadrature.h>
#include "kernels.h"
#include "integrands.h"
#include <deque>

using namespace std;

struct CachedValue {
	real k;
	real ps;
	CachedValue(real new_k, real new_ps) : k(new_k), ps(new_ps) {}
};

static int computeIntegrals(int argc, char** args) {
	
	int nIntegrals = 1;
	if (argc > 1) {
		try {
			nIntegrals = atoi(args[1]);
		}
		catch (const std::exception e) {}
	}	

	const Cosmology C (.688,.971,.295,.0473);
	const InterpolatedPS ps (C, "p11cambDM.dat");
	
	ofstream data ("integrals_noresum.txt");
	
	real klist[100] = {0.01043818,0.01532369,0.02157276,0.02834865,
			0.03456784,0.04079704,0.0469901,0.05308914,
			0.05954472,0.06582334,0.07193966,0.07824595,
			0.08475764,0.09121436,0.0973611,0.1035747,
			0.1098226,0.116044,0.1223865,0.1286908,
			0.1349423,0.1411876,0.1475008,0.1537725,
			0.1600564,0.1663951,0.1727325,0.1790439,
			0.1853209,0.1915728,0.1978322,0.2041849,
			0.2104981,0.2167137,0.2229646,0.2292547,
			0.2355059,0.2417865,0.2480881,0.2543503,
			0.2606232,0.2669563,0.2732767,0.2796161,
			0.2858967,0.2921163,0.2983731,0.3046781,
			0.3109607,0.3172621,0.3235839,0.3298394,
			0.33614,0.3423984,0.3486832,0.3549478,
			0.3612031,0.3674905,0.3737731,0.3800737,
			0.3863721,0.3926236,0.3989204,0.4052014,
			0.4115043,0.4177986,0.4240402,0.4303546,
			0.4366253,0.4429172,0.4491835,0.4554587,
			0.4617794,0.4680951,0.4743754,0.4806578,
			0.4869284,0.4931946,0.4994603,0.505717,
			0.5119997,0.5183364,0.5246104,0.5308601,
			0.5371657,0.5435141,0.5497636,0.5559643,
			0.562279,0.5686446,0.5749155,0.5811334,
			0.5874276,0.5937501,0.6000223,0.6062977,
			0.6125227,0.6188515,0.6251628,0.6313986};

	deque <CachedValue> cache;
	for (int i = 0; i < 6; i++) {
		cache.push_back(CachedValue(0,0));
	}
	auto check_cache = [](deque<CachedValue> &cache, real x) {
		for (int i = 0; i < cache.size(); i++) {
			if (x == cache[i].k)
				return i;
		}
		return -1;
	};

	double ranges [2][2] = {{-1.,0.001},{1.,20.}};

	for (int i = 1; i <= nIntegrals; i++) {
		for (real k : klist) {
			data << k << " " << 
				Integrate<2>([&](real x, real q) { 
					return q*q/(Power(2*Pi,3))*Integrand(i, k, q, x, [&] (real kk) -> const real {
						int index = check_cache(cache, kk);
						if (index == -1) {
							cache.pop_back();
							cache.push_front(CachedValue(kk, ps.Evaluate(kk)));
						}
						else {
							cache.push_front(cache[index]);
							cache.erase(cache.begin() + index + 1);
						}
						return cache[0].ps;
						});
					}, ranges[0], ranges[1],  0.001) << endl;
			}

	}
	data.close();
	return 0;
}


int main(int argc, char** args) {
		return computeIntegrals(argc, args);
}
