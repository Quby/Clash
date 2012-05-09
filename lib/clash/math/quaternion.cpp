#include<clash/math.cpp>
//@todo Euler
Quaternion::Quaternion() {
	v = new Vector3(0, 0, 0);
	w = 1;
}

Quaternion::Quaternion(Vector3* vec, float w) {
	v = new Vector3(vec);
	w = 1;
}

Quaternion::Quaternion(float x, float y, float z, float w) {
	v = new Vector3(x, y, z);
	w = 1;
}

Quaternion::Quaternion(Quaternion& q) {
	v = new Vector3(q.v);
	w = q.w;
}

Quaternion::~Quaternion() {
	delete v;
}

Quaternion::operator+=(Quaternion& q) {
	v += q.v;
	w += q.w;
}

Quaternion::operator-=(Quaternion& q) {
	v -= q.v;
	w -= q.w;
}

Quaternion::operator*=(float t) {
	v *= t;
	w *= t;
}

void Quaternion::conjugate () {
	v.invert();
}

void Quaternion::normalize () {
	float t = sqrt(x*x+y*y+z*z+w*w);
	w /= t;
	v /= t;
}

void Quaternion::operator+= (Quaternion& s) {
	v += s.v;
	w += s.w;
}

void Quaternion::operator-= (Quaternion& s) {
	v -= s.v;
	w -= s.w;
}

void Quaternion::operator*= (float s) {
	v *= s;
	w *= s;
}

void Quaternion::operator*= (Quaternion& s) {
	v *= s.v;
	
	wvt = Vector(s.v);
	wvt *= w;
	
	wtv = Vector(v);
	wtv *= s.w;
	
	v += wvt;
	v += wtv;
	delete wvt;
	delete wtv;
	
	w = w*s.w - (float)v*s.v;
}
