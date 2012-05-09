#include<clash/math.cpp>
#include "math.h"

using namespace clash::math;

Quaternion::Quaternion(float sx=0.f, float sy=0.f, float sz=0.f, float sw=1.f) {
	x = sx;
	y = sy;
	z = sz;
	w = sw;
}

Quaternion& Quaternion::Euler(float heading, float attitude, float bank){
	float c1 = cosf(heading);
	float s1 = sinf(heading);
	float c2 = cosf(attitude);
	float s2 = sinf(attitude);
	float c3 = cosf(bank);
	float s3 = sinf(bank);
	w = sqrt(1.0 + c1 * c2 + c1*c3 - s1 * s2 * s3 + c2*c3) / 2.0;
	float w4 = (4.0 * w);
	x = (c2 * s3 + c1 * s3 + s1 * s2 * c3) / w4 ;
	y = (s1 * c2 + s1 * c3 + c1 * s2 * s3) / w4 ;
	z = (-s1 * s3 + c1 * s2 * c3 +s2) / w4 ;
	return *(new Quaternion(x, y, z, w));
}

Quaternion::operator+=(Quaternion& q) {
	x += q.x;
	y += q.y;
	z += z.y;
	w += q.w;
}

Quaternion::operator-=(Quaternion& q) {
	x -= q.x;
	y -= q.y;
	z -= z.y;
	w -= q.w;
}

Quaternion::operator*=(float t) {
	x *= t;
	y *= t;
	z *= t;
	w *= t;
}

void Quaternion::conjugate () {
	x = -x;
	y = -y;
	z = -z;
}

void Quaternion::normalize () {
	float t = sqrt(x*x+y*y+z*z+w*w);
	x /= t;
	y /= t;
	z /= t
	w /= t;
}

void Quaternion::operator+= (Quaternion& q) {
	x += q.x;
	y += q.y;
	z += q.z;
	w += q.w;
}

void Quaternion::operator-= (Quaternion& q) {
	x -= q.x;
	y -= q.y;
	z -= q.z;
	w -= q.w;
}

void Quaternion::operator*= (Quaternion& q) {
	x = y*q.z - q.y*z + w*q.x + q.w*x;
	y = z*q.x - q.z*x + w*q.y + q.w*y;
	z = x*q.y - q.x*y + w*q.z + q.w*z;
	w = w*q.w - x*q.x - y*q.y - z*q.z;
}
