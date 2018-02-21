#ifndef KERNELS_H
#define KERNELS_H

#include "vec3.h"
#include <Copter/Common.h>

//\hat{c} kernels

real c1(const vec3 & q1);
real c2(short n, const vec3 & q1, const vec3 & q2);
real c3(short n, const vec3 & q1, const vec3 & q2, const vec3 & q3);

real c2_1(const vec3 & q1, const vec3 & q2);
real c2_2(const vec3 & q1, const vec3 & q2);
real c2_3(const vec3 & q1, const vec3 & q2);
real c2_4(const vec3 & q1, const vec3 & q2);

real c3_1(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_2(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_3(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_4(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_5(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_6(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_7(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_8(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_9(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_10(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_11(const vec3 & q1, const vec3 & q2, const vec3 & q3);
real c3_12(const vec3 & q1, const vec3 & q2, const vec3 & q3);

real K2(const vec3 & q1, const vec3 & q2, const real * coeffs);
real K3(const vec3 & q1, const vec3 & q2, const vec3 & q3, const real * coeffs);

#endif

