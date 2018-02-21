#include "vec3.h"

vec3 operator-(const vec3& p) {
	return vec3(-p.x, -p.y, -p.z);
}
vec3 operator+(const vec3& p, const vec3& q) {
	return vec3(p.x + q.x, p.y + q.y, p.z + q.z);
}

vec3 operator-(const vec3& p, const vec3& q) {
	return vec3(p.x - q.x, p.y - q.y, p.z - q.z);
}

vec3 operator*(real a, const vec3& p) {
     return vec3(a*p.x, a*p.y, a*p.z);
}

vec3 operator*(const vec3& p, real a) {
 return vec3(p.x*a, p.y*a, p.z*a);
}

vec3 operator/(const vec3& p, real a) {
	return vec3(p.x/a, p.y/a, p.z/a);
}

real operator*(const vec3& p, const vec3& q) {
	return p.x*q.x + p.y*q.y + p.z*q.z;
}
