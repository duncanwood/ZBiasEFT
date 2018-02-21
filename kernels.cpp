#include "kernels.h"
#include "mdefs.h"
#include "vec3.h"

real c1(const vec3 & q1) {
	return 1;
}

real c2(short n, const vec3 & q1, const vec3 & q2) {
	switch (n) {
		case 1:
			return c2_1(q1, q2);
		case 2: 
			return c2_2(q1, q2);
		case 3:
			return c2_3(q1, q2);
		case 4:
			return c2_4(q1, q2);
	}
}

real c3(short n, const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	switch (n) {
		case 1:
			return c3_1(q1, q2, q3);
		case 2:
			return c3_2(q1, q2, q3);
		case 3:
			return c3_3(q1, q2, q3);
		case 4:
			return c3_4(q1, q2, q3);
		case 5:
			return c3_5(q1, q2, q3);
		case 6:
			return c3_6(q1, q2, q3);
		case 7:
			return c3_7(q1, q2, q3);
		case 8:
			return c3_8(q1, q2, q3);
		case 9:
			return c3_9(q1, q2, q3);
		case 10:
			return c3_10(q1, q2, q3);
		case 11:
			return c3_11(q1, q2, q3);
		case 12:
			return c3_12(q1, q2, q3);
	}
}

real c2_1(const vec3 & q1, const vec3 & q2) {
	return Dot(q1,q2)/Dot(q1,q1);
}

real c2_2(const vec3 & q1, const vec3 & q2) {
	return -(Dot(q1,q2)/Dot(q1,q1)) + ((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.;
}

real c2_3(const vec3 & q1, const vec3 & q2) {
	return 1;
}

real c2_4(const vec3 & q1, const vec3 & q2) {
	return -1/3. + Power(Dot(q1,q2),2)/(Dot(q1,q1)*Dot(q2,q2));
}



real c3_1(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return ((Dot(q1,q2)*(Dot(q1,q3) + Dot(q2,q3)))/(Dot(q2,q2)*Dot(q3,q3)) + ((Dot(q1,q2) + Dot(q1,q3))*(((3*Dot(q2 + q3,q2))/Dot(q2,q2) + (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))/14. + ((3*Dot(q2 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))/14.))/Dot(q2 + q3,q2 + q3))/2.;
}

real c3_2(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return ((Dot(q1,q3) + Dot(q2,q3))*(-Dot(q1,q2) + Dot(q2,q2)*(((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.)))/(Dot(q2,q2)*Dot(q3,q3));
}

real c3_3(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return ((Dot(q1,q2) - 2*Dot(q2,q2)*(((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.))*Dot(q1 + q2,q3))/(2.*Dot(q2,q2)*Dot(q3,q3)) - (Dot(q1,q2 + q3)*(((3*Dot(q2 + q3,q2))/Dot(q2,q2) + (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))/14. + ((3*Dot(q2 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))/14.))/(2.*Dot(q2 + q3,q2 + q3)) + (((((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q1 + q2 + q3,q3))/Dot(q3,q3) + (((3*Dot(q1 + q2,q1))/Dot(q1,q1) + (2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/18. + (((3*Dot(q1 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*((7*Dot(q1 + q2 + q3,q1 + q3))/Dot(q1 + q3,q1 + q3) + (Dot(q1 + q3,q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q2,q2)*Dot(q1 + q3,q1 + q3))))/126.)/6. + ((((3*Dot(q1 + q2,q2))/Dot(q2,q2) + (2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*((7*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + (Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))))/126. + ((((5*Dot(q1 + q3,q1))/Dot(q1,q1) + (Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q2))/Dot(q2,q2) + (Dot(q2,q1 + q3)*((3*Dot(q1 + q3,q1))/Dot(q1,q1) + (2*Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q2,q2)*Dot(q1 + q3,q1 + q3)))/18.)/6. + (((((5*Dot(q1 + q3,q3))/Dot(q3,q3) + (Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q2))/Dot(q2,q2) + (Dot(q2,q1 + q3)*((3*Dot(q1 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q2,q2)*Dot(q1 + q3,q1 + q3)))/18. + (((3*Dot(q2 + q3,q2))/Dot(q2,q2) + (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*((7*Dot(q1 + q2 + q3,q2 + q3))/Dot(q2 + q3,q2 + q3) + (Dot(q2 + q3,q1)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1,q1)*Dot(q2 + q3,q2 + q3))))/126.)/6. + (((((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q1 + q2 + q3,q3))/Dot(q3,q3) + (((3*Dot(q1 + q2,q2))/Dot(q2,q2) + (2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/18. + (((3*Dot(q2 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*((7*Dot(q1 + q2 + q3,q2 + q3))/Dot(q2 + q3,q2 + q3) + (Dot(q2 + q3,q1)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1,q1)*Dot(q2 + q3,q2 + q3))))/126.)/6. + ((((3*Dot(q1 + q2,q1))/Dot(q1,q1) + (2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*((7*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + (Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))))/126. + ((((5*Dot(q2 + q3,q2))/Dot(q2,q2) + (Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1))/Dot(q1,q1) + (Dot(q1,q2 + q3)*((3*Dot(q2 + q3,q2))/Dot(q2,q2) + (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1,q1)*Dot(q2 + q3,q2 + q3)))/18.)/6. + ((((3*Dot(q1 + q3,q1))/Dot(q1,q1) + (2*Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*((7*Dot(q1 + q2 + q3,q1 + q3))/Dot(q1 + q3,q1 + q3) + (Dot(q1 + q3,q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q2,q2)*Dot(q1 + q3,q1 + q3))))/126. + ((((5*Dot(q2 + q3,q3))/Dot(q3,q3) + (Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1))/Dot(q1,q1) + (Dot(q1,q2 + q3)*((3*Dot(q2 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1,q1)*Dot(q2 + q3,q2 + q3)))/18.)/6.;
}

real c3_4(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return (2*Dot(q2,q3))/Dot(q3,q3);
}

real c3_5(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return  2*(((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.) - (2*Dot(q2,q3))/Dot(q3,q3);
}
real c3_6(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return 1;
}
real c3_7(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return (2*(-0.3333333333333333 + Power(Dot(q1,q2),2)/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q2,q3))/Dot(q3,q3);
}
real c3_8(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return 2*(((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.)*(-0.3333333333333333 + Power(Dot(q1 + q2,q3),2)/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))) - (2*(-0.3333333333333333 + Power(Dot(q1,q2),2)/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q2,q3))/Dot(q3,q3);
}

real c3_9(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return (-3*Power(Dot(q1,q3),2)*Dot(q2,q2) + 9*Dot(q1,q2)*Dot(q1,q3)*Dot(q2,q3) - 3*Power(Dot(q1,q2),2)*Dot(q3,q3) + Dot(q1,q1)*(-3*Power(Dot(q2,q3),2) + 2*Dot(q2,q2)*Dot(q3,q3)))/(9.*Dot(q1,q1)*Dot(q2,q2)*Dot(q3,q3));
}
real c3_10(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
		return (((-5*Dot(q1 + q2,q1))/Dot(q1,q1) - (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((3*Dot(q1 + q2,q1))/Dot(q1,q1) + (2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((-5*Dot(q1 + q2,q2))/Dot(q2,q2) - (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((3*Dot(q1 + q2,q2))/Dot(q2,q2) + (2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.)*(-0.3333333333333333 + Power(Dot(q1 + q2,q3),2)/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3)));
}
real c3_11(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
		return 2*(((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.)*(((-3*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) - (2*Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/14. + ((5*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + (Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/14. + ((-3*Dot(q1 + q2 + q3,q3))/Dot(q3,q3) - (2*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/14. + ((5*Dot(q1 + q2 + q3,q3))/Dot(q3,q3) + (Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/14.) + ((-((((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q1 + q2 + q3,q3))/Dot(q3,q3)) - (((3*Dot(q1 + q2,q1))/Dot(q1,q1) + (2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/18. - (((3*Dot(q1 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*((7*Dot(q1 + q2 + q3,q1 + q3))/Dot(q1 + q3,q1 + q3) + (Dot(q1 + q3,q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q2,q2)*Dot(q1 + q3,q1 + q3))))/126.)/6. + (((3*((5*Dot(q1 + q2,q1))/Dot(q1,q1) + (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q1 + q2 + q3,q3))/(7.*Dot(q3,q3)) + (3*((3*Dot(q1 + q2,q1))/Dot(q1,q1) + (2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/18. + (((3*Dot(q1 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*((3*Dot(q1 + q2 + q3,q1 + q3))/Dot(q1 + q3,q1 + q3) + (3*Dot(q1 + q3,q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q2,q2)*Dot(q1 + q3,q1 + q3))))/126.)/6. + (-(((3*Dot(q1 + q2,q2))/Dot(q2,q2) + (2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*((7*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + (Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))))/126. + (-((((5*Dot(q1 + q3,q1))/Dot(q1,q1) + (Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q2))/Dot(q2,q2)) - (Dot(q2,q1 + q3)*((3*Dot(q1 + q3,q1))/Dot(q1,q1) + (2*Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q2,q2)*Dot(q1 + q3,q1 + q3)))/18.)/6. + ((((3*Dot(q1 + q2,q2))/Dot(q2,q2) + (2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*((3*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + (3*Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))))/126. + ((3*((5*Dot(q1 + q3,q1))/Dot(q1,q1) + (Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q2))/(7.*Dot(q2,q2)) + (3*Dot(q2,q1 + q3)*((3*Dot(q1 + q3,q1))/Dot(q1,q1) + (2*Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q2,q2)*Dot(q1 + q3,q1 + q3)))/18.)/6. + ((-((((5*Dot(q1 + q3,q3))/Dot(q3,q3) + (Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q2))/Dot(q2,q2)) - (Dot(q2,q1 + q3)*((3*Dot(q1 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q2,q2)*Dot(q1 + q3,q1 + q3)))/18. - (((3*Dot(q2 + q3,q2))/Dot(q2,q2) + (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*((7*Dot(q1 + q2 + q3,q2 + q3))/Dot(q2 + q3,q2 + q3) + (Dot(q2 + q3,q1)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1,q1)*Dot(q2 + q3,q2 + q3))))/126.)/6. + ((-((((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q1 + q2 + q3,q3))/Dot(q3,q3)) - (((3*Dot(q1 + q2,q2))/Dot(q2,q2) + (2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/18. - (((3*Dot(q2 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*((7*Dot(q1 + q2 + q3,q2 + q3))/Dot(q2 + q3,q2 + q3) + (Dot(q2 + q3,q1)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1,q1)*Dot(q2 + q3,q2 + q3))))/126.)/6. + (((3*((5*Dot(q1 + q3,q3))/Dot(q3,q3) + (Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q2))/(7.*Dot(q2,q2)) + (3*Dot(q2,q1 + q3)*((3*Dot(q1 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q2,q2)*Dot(q1 + q3,q1 + q3)))/18. + (((3*Dot(q2 + q3,q2))/Dot(q2,q2) + (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*((3*Dot(q1 + q2 + q3,q2 + q3))/Dot(q2 + q3,q2 + q3) + (3*Dot(q2 + q3,q1)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1,q1)*Dot(q2 + q3,q2 + q3))))/126.)/6. + (((3*((5*Dot(q1 + q2,q2))/Dot(q2,q2) + (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q1 + q2 + q3,q3))/(7.*Dot(q3,q3)) + (3*((3*Dot(q1 + q2,q2))/Dot(q2,q2) + (2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/18. + (((3*Dot(q2 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*((3*Dot(q1 + q2 + q3,q2 + q3))/Dot(q2 + q3,q2 + q3) + (3*Dot(q2 + q3,q1)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1,q1)*Dot(q2 + q3,q2 + q3))))/126.)/6. + (-(((3*Dot(q1 + q2,q1))/Dot(q1,q1) + (2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*((7*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + (Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))))/126. + (-((((5*Dot(q2 + q3,q2))/Dot(q2,q2) + (Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1))/Dot(q1,q1)) - (Dot(q1,q2 + q3)*((3*Dot(q2 + q3,q2))/Dot(q2,q2) + (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1,q1)*Dot(q2 + q3,q2 + q3)))/18.)/6. + ((((3*Dot(q1 + q2,q1))/Dot(q1,q1) + (2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*((3*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + (3*Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))))/126. + ((3*((5*Dot(q2 + q3,q2))/Dot(q2,q2) + (Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1))/(7.*Dot(q1,q1)) + (3*Dot(q1,q2 + q3)*((3*Dot(q2 + q3,q2))/Dot(q2,q2) + (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1,q1)*Dot(q2 + q3,q2 + q3)))/18.)/6. + (-(((3*Dot(q1 + q3,q1))/Dot(q1,q1) + (2*Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*((7*Dot(q1 + q2 + q3,q1 + q3))/Dot(q1 + q3,q1 + q3) + (Dot(q1 + q3,q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q2,q2)*Dot(q1 + q3,q1 + q3))))/126. + (-((((5*Dot(q2 + q3,q3))/Dot(q3,q3) + (Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1))/Dot(q1,q1)) - (Dot(q1,q2 + q3)*((3*Dot(q2 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1,q1)*Dot(q2 + q3,q2 + q3)))/18.)/6. + ((((3*Dot(q1 + q3,q1))/Dot(q1,q1) + (2*Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*((3*Dot(q1 + q2 + q3,q1 + q3))/Dot(q1 + q3,q1 + q3) + (3*Dot(q1 + q3,q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/(Dot(q2,q2)*Dot(q1 + q3,q1 + q3))))/126. + ((3*((5*Dot(q2 + q3,q3))/Dot(q3,q3) + (Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1))/(7.*Dot(q1,q1)) + (3*Dot(q1,q2 + q3)*((3*Dot(q2 + q3,q3))/Dot(q3,q3) + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*Dot(q1 + q2 + q3,q1 + q2 + q3))/(7.*Dot(q1,q1)*Dot(q2 + q3,q2 + q3)))/18.)/6.;
}
real c3_12(const vec3 & q1, const vec3 & q2, const vec3 & q3) {
	return -1/3. + Power(Dot(q1,q2),2)/(Dot(q1,q1)*Dot(q2,q2));
}


real K2(const vec3 & q1, const vec3 & q2, const real * coeffs) {
	return (Dot(q1,q2)*coeffs[1])/Dot(q1,q1) + 
	   (-(Dot(q1,q2)/Dot(q1,q1)) + 
	         ((5*Dot(q1 + q2,q1))/Dot(q1,q1) + 
			          (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14. + 
					        ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + 
							         (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.)*
									     coeffs[2] + coeffs[6];
}
real K3(const vec3 & q1, const vec3 & q2, const vec3 & q3, const real * coeffs) {
		return (((Dot(q1,q2)*(Dot(q1,q3) + Dot(q2,q3)))/(Dot(q2,q2)*Dot(q3,q3)) + 
								((Dot(q1,q2) + Dot(q1,q3))*
								 (((3*Dot(q2 + q3,q2))/Dot(q2,q2) + 
								   (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))/14. 
								  + ((3*Dot(q2 + q3,q3))/Dot(q3,q3) 
										  + (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))/14.))
								/Dot(q2 + q3,q2 + q3))*coeffs[1])/2. 
				+((Dot(q1,q3) + Dot(q2,q3))*(-Dot(q1,q2) 
										+Dot(q2,q2)*(((5*Dot(q1 + q2,q1))/Dot(q1,q1) + 
														(Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.
												+ ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + 
														(Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.
												))*coeffs[3])/(Dot(q2,q2)*Dot(q3,q3)) + 
				(((Dot(q1,q2) - 2*Dot(q2,q2)*
				   (((5*Dot(q1 + q2,q1))/Dot(q1,q1) + 
					 (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/
					14. + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + 
							(Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/
					14.))*Dot(q1 + q2,q3))/(2.*Dot(q2,q2)*Dot(q3,q3)) - 
				 (Dot(q1,q2 + q3)*(((3*Dot(q2 + q3,q2))/Dot(q2,q2) + 
									(2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))/
								   14. + ((3*Dot(q2 + q3,q3))/Dot(q3,q3) + 
										   (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))/
								   14.))/(2.*Dot(q2 + q3,q2 + q3)) + 
				 (((((5*Dot(q1 + q2,q1))/Dot(q1,q1) + 
					 (Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*
					Dot(q1 + q2 + q3,q3))/Dot(q3,q3) + 
				   (((3*Dot(q1 + q2,q1))/Dot(q1,q1) + 
					 (2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2))
					)*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
				   (7.*Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/18. + 
				  (((3*Dot(q1 + q3,q3))/Dot(q3,q3) + 
					(2*Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*
				   ((7*Dot(q1 + q2 + q3,q1 + q3))/Dot(q1 + q3,q1 + q3) + 
					(Dot(q1 + q3,q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
					(Dot(q2,q2)*Dot(q1 + q3,q1 + q3))))/126.)/6. + 
				 ((((3*Dot(q1 + q2,q2))/Dot(q2,q2) + 
					(2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*
				   ((7*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + 
					(Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
					(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))))/126. + 
				  ((((5*Dot(q1 + q3,q1))/Dot(q1,q1) + 
					 (Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*
					Dot(q1 + q2 + q3,q2))/Dot(q2,q2) + 
				   (Dot(q2,q1 + q3)*((3*Dot(q1 + q3,q1))/Dot(q1,q1) + 
									 (2*Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3))
									)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
				   (7.*Dot(q2,q2)*Dot(q1 + q3,q1 + q3)))/18.)/6. + 
				 (((((5*Dot(q1 + q3,q3))/Dot(q3,q3) + 
					 (Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*
					Dot(q1 + q2 + q3,q2))/Dot(q2,q2) + 
				   (Dot(q2,q1 + q3)*((3*Dot(q1 + q3,q3))/Dot(q3,q3) + 
									 (2*Dot(q3,q1)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3))
									)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
				   (7.*Dot(q2,q2)*Dot(q1 + q3,q1 + q3)))/18. + 
				  (((3*Dot(q2 + q3,q2))/Dot(q2,q2) + 
					(2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*
				   ((7*Dot(q1 + q2 + q3,q2 + q3))/Dot(q2 + q3,q2 + q3) + 
					(Dot(q2 + q3,q1)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
					(Dot(q1,q1)*Dot(q2 + q3,q2 + q3))))/126.)/6. + 
				 (((((5*Dot(q1 + q2,q2))/Dot(q2,q2) + 
					 (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*
					Dot(q1 + q2 + q3,q3))/Dot(q3,q3) + 
				   (((3*Dot(q1 + q2,q2))/Dot(q2,q2) + 
					 (2*Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2))
					)*Dot(q3,q1 + q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
				   (7.*Dot(q1 + q2,q1 + q2)*Dot(q3,q3)))/18. + 
				  (((3*Dot(q2 + q3,q3))/Dot(q3,q3) + 
					(2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*
				   ((7*Dot(q1 + q2 + q3,q2 + q3))/Dot(q2 + q3,q2 + q3) + 
					(Dot(q2 + q3,q1)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
					(Dot(q1,q1)*Dot(q2 + q3,q2 + q3))))/126.)/6. + 
				 ((((3*Dot(q1 + q2,q1))/Dot(q1,q1) + 
					(2*Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))*
				   ((7*Dot(q1 + q2 + q3,q1 + q2))/Dot(q1 + q2,q1 + q2) + 
					(Dot(q1 + q2,q3)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
					(Dot(q1 + q2,q1 + q2)*Dot(q3,q3))))/126. + 
				  ((((5*Dot(q2 + q3,q2))/Dot(q2,q2) + 
					 (Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*
					Dot(q1 + q2 + q3,q1))/Dot(q1,q1) + 
				   (Dot(q1,q2 + q3)*((3*Dot(q2 + q3,q2))/Dot(q2,q2) + 
									 (2*Dot(q2,q3)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3))
									)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
				   (7.*Dot(q1,q1)*Dot(q2 + q3,q2 + q3)))/18.)/6. + 
				 ((((3*Dot(q1 + q3,q1))/Dot(q1,q1) + 
					(2*Dot(q1,q3)*Dot(q1 + q3,q1 + q3))/(Dot(q1,q1)*Dot(q3,q3)))*
				   ((7*Dot(q1 + q2 + q3,q1 + q3))/Dot(q1 + q3,q1 + q3) + 
					(Dot(q1 + q3,q2)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
					(Dot(q2,q2)*Dot(q1 + q3,q1 + q3))))/126. + 
				  ((((5*Dot(q2 + q3,q3))/Dot(q3,q3) + 
					 (Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3)))*
					Dot(q1 + q2 + q3,q1))/Dot(q1,q1) + 
				   (Dot(q1,q2 + q3)*((3*Dot(q2 + q3,q3))/Dot(q3,q3) + 
									 (2*Dot(q3,q2)*Dot(q2 + q3,q2 + q3))/(Dot(q2,q2)*Dot(q3,q3))
									)*Dot(q1 + q2 + q3,q1 + q2 + q3))/
				   (7.*Dot(q1,q1)*Dot(q2 + q3,q2 + q3)))/18.)/6.)*coeffs[4] + 
				   (2*Dot(q2,q3)*coeffs[7])/Dot(q3,q3) + 
				   (2*(((5*Dot(q1 + q2,q1))/Dot(q1,q1) + 
						(Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.\
					   + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + 
							   (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.)\
					- (2*Dot(q2,q3))/Dot(q3,q3))*coeffs[8] + 
				   (2*(((5*Dot(q1 + q2,q1))/Dot(q1,q1) + 
						(Dot(q1,q2)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.\
					   + ((5*Dot(q1 + q2,q2))/Dot(q2,q2) + 
							   (Dot(q2,q1)*Dot(q1 + q2,q1 + q2))/(Dot(q1,q1)*Dot(q2,q2)))/14.)*
					(-0.3333333333333333 + Power(Dot(q1 + q2,q3),2)/
					 (Dot(q1 + q2,q1 + q2)*Dot(q3,q3))) - 
					(2*(-0.3333333333333333 + 
						Power(Dot(q1,q2),2)/(Dot(q1,q1)*Dot(q2,q2)))*Dot(q2,q3))/
					Dot(q3,q3))*coeffs[9] + coeffs[10];
}
