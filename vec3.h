#ifndef VEC3
#define VEC3


#include <Copter/Common.h>

/*******************************************************************
 *  * Definitions of vectors and kernels (from Copter) (from CosmoEFT)
 *   ********************************************************************/

/* vec3: a simple 3-dimensional vector class */
struct vec3 {
    double x, y, z;

    vec3() { x = y = z = 0; }
    vec3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
    vec3(const vec3& q) : x(q.x), y(q.y), z(q.z) {}

    void operator+=(const vec3& p) {
        x += p.x; y += p.y; z += p.z;
    }
    void operator-=(const vec3& p) {
        x -= p.x; y -= p.y; z -= p.z;
    }
    void operator*=(double a) {
        x *= a; y *= a; z *= a;
    }
    void operator/=(double a) {
        x /= a; y /= a; z /= a;
    }
    double square() const {
        return x*x + y*y + z*z;
    }
    double mag() const {
        return sqrt(square());
    }
};
vec3 operator-(const vec3& p);
vec3 operator+(const vec3& p, const vec3& q);
vec3 operator-(const vec3& p, const vec3& q);
vec3 operator*(real a, const vec3& p);
vec3 operator*(const vec3& p, real a);
vec3 operator/(const vec3& p, real a);
double operator*(const vec3& p, const vec3& q);
/*
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

double operator*(const vec3& p, const vec3& q) {
    return p.x*q.x + p.y*q.y + p.z*q.z;
}
*/
#endif
