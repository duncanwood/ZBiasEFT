#include "mdefs.h"
#include "vec3.h"
#include <iostream>
#include <fstream>
#include <Copter/GrowthFunction.h>
#include <Copter/InterpolatedPS.h>
#include <Copter/Cosmology.h>
#include <Copter/Quadrature.h>
#include "kernels.h"
#include "integrands.h"

using namespace std;


int test1() {
	vec3 v (1.,2.,3.);
	vec3 w = v+v;
	vec3 v1 (1, 2,  3);
	vec3 v2 (5, -1, 2);
	vec3 v3 (-1, 3, 4);
	real coeffs [14] = {0,1.6104001172697386,1.3968722737867396,
				1.1548119602404654,0.5986928441620107,
				0.7877253272927272,1.0416740075755633,
				1.18373842754725,1.049831274625591,
				1.8579695766190194,1.029707660797118,
				1.7534242467146504,1.0395350862065085,
				1.4303489782311694};
	/*
	   for (int i = 1; i <= 4; i++) {
	   cout << "c_2_" << i << "(v1,v2) = " << c2(i, v1,v2) << endl;
	   }
   */
	for (int i = 1; i <= 12; i++) {
		cout << "c_3_" << i << "(v1,v2,v3) = " << c3(i, v1,v2,v3) << endl;
	}

	cout << "K2(v1,v2,coeffs) = " << K2(v1,v2,coeffs) << endl;
	cout << "K2(v2,v1,coeffs) = " << K2(v2,v1,coeffs) << endl;

	cout << "K3(v1,v2,v3,coeffs) = " << K3(v1,v2,v3,coeffs) << endl;
	cout << "K3(v1,v3,v2,coeffs) = " << K3(v1,v3,v2,coeffs) << endl;
	cout << "K3(v2,v3,v1,coeffs) = " << K3(v2,v3,v1,coeffs) << endl;
	cout << "K3(v2,v1,v3,coeffs) = " << K3(v2,v1,v3,coeffs) << endl;
	cout << "K3(v3,v2,v1,coeffs) = " << K3(v3,v2,v1,coeffs) << endl;
	cout << "K3(v3,v1,v2,coeffs) = " << K3(v3,v1,v2,coeffs) << endl;


	return 0;
}

static int testIntegrands(int argc, char** args) {
	
	int nIntegrals = 1;
	if (argc > 1) {
		try {
			nIntegrals = atoi(args[1]);
		}
		catch (const std::exception e) {}
	}	

	Cosmology C (.688,.971,.295,.0473);
	InterpolatedPS ps (C, "p11cambDM.dat");
	
	cout << Integrand_1(1,2,.5,[&ps] (real k) {return ps.Evaluate(k);}) << endl;/*
	cout << Integrand_2 << endl;
	cout << Integrand_3 << endl;
	cout << Integrand_5 << endl;
	cout << Integrand_7 << endl;
	cout << Integrand_10 << endl;
	cout << Integrand_30 << endl;
	cout << Integrand_35 << endl;
	cout << Integrand_43 << endl;


*/
	ofstream data ("data.txt");
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
	/*	Range ranges [2];
		ranges[0].a = -1.;
		ranges[0].b = 1.;
		ranges[1].a = 0.001;
		ranges[1].b = 20;
	mc MonteCarloIntegral(2, 1, &ranges);
*/

	double ranges [2][2] = {{-1.,0.001},{1.,20.}};
	for (int i = 0; i <= nIntegrals; i++) {
		for (real k : klist) {
			data << k << " " << 
				Integrate<2>([&](real x, real q) { 
					return q*q/(Power(2*Pi,3))*Integrand(i, k, q, x, [&ps] (real k) {
						return ps.Evaluate(k);
						});
					}, ranges[0], ranges[1],  0.001) << endl;
			}

	}
	data.close();
	return 0;
}


int main(int argc, char** args) {
		return testIntegrands(argc, args);
}
