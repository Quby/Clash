#include<clash/math.hpp>
//@todo *=(Matrix4)
using namespace clash::math;

Vector3::Vector3(float sx=0.f, float sy=0.f, float sz=0.f) {
	x = sx;
	y = sy;
	z = sz;
}

void Vector3::invert () {
	x = -x;
	y = -y;
	z = -z;
}

float Vector3::len () {
	return sqrt(x*x + y*y + z*z);
}

//Operations with scalar
void Vector3::operator+= (Vector3& vec) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

void Vector3::operator-= (Vector3& vec) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}

void Vector3::operator*= (float t) {
	x *= t;
	y *= t;
	z *= t;
}

void Vector3::operator/= (float t) {
	x /= t;
	y /= t;
	z /= t;
}

//Operations with vector
void Vector3::operator*= (Vector3& vec) {
	float dx, dy, dz;
	dx = y*vec.z - vec.y*z;
	dy = z*vec.x - vec.z*x;
	dz = x*vec.y - vec.x*y;
	
	x = dx;
	y = dy;
	z = dz;	
}


float Vector3::operator* (Vector3& vec) {
	return sqrt(x*vec.x + y*vec.y + z*vec.z);
}

void Vector3::operator* (Quaternion& q) {
	Quaternion vec(this, 0.f);
	Quaternion res(q);
	res.conjugate();
	res *= vec;
	res *= q;
}




