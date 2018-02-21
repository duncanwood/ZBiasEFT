#include "mdefs.h"
#include "vec3.h"
#include <iostream>
#include "kernels.h"

using namespace std;

int main(int argc, char** args) {
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
