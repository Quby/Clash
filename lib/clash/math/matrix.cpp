#include<clash/math.cpp>
#include "math.h"

using namespace clash::math;

Matrix4::Matrix4 () {
	a = new float[16];
	
	a[ 0] = 1;	a[ 1] = 0;	a[ 2] = 0;	a[ 3] = 0;
	a[ 4] = 0;	a[ 5] = 1;	a[ 6] = 0;	a[ 7] = 0;
	a[ 8] = 0;	a[ 9] = 0;	a[10] = 1;	a[11] = 0;
	a[12] = 0;	a[13] = 0;	a[14] = 0;	a[15] = 1;
}

Matrix4::Matrix4 (const Matrix4& b) {
	a = new float[16];
	for (unsigned register char i = 0; i < 16; ++i) {
		a[i] = b[i];
	}
}

Matrix4::Matrix(Quaternion& q) {
	q.normalize();
	a[ 0] = +q.w; a[ 1] = +q.z; a[ 2] = -q.y; a[ 3] = q.x;
	a[ 4] = -q.z; a[ 5] = +q.w; a[ 6] = +q.x; a[ 7] = q.y;
	a[ 8] = +q.y; a[ 9] = -q.x; a[10] = +q.w; a[11] = q.z;
	a[12] = -q.x; a[13] = -q.y; a[14] = -q.z; a[15] = q.w;

	Matrix4 m;

	m[ 0] = +q.w; m[ 1] = +q.z; m[ 2] = -q.y; m[ 3] = +q.x;
	m[ 4] = -q.z; m[ 5] = +q.w; m[ 6] = +q.x; m[ 7] = -q.y;
	m[ 8] = +q.y; m[ 9] = -q.x; m[10] = +q.w; m[11] = -q.z;
	m[12] = +q.x; m[13] = +q.y; m[14] = +q.z; m[15] = +q.w;

	(*this)*= m;
}

Matrix4::~Matrix4 () {
	delete a;
}

float& Matrix4::operator[](int idx) {
	return a[idx];
}

void Matrix4::operator*=(Matrix4& b) {
	float c[16];
	c[ 0] = a[ 0] * b[ 0] + a[ 1] * b[ 4] + a[ 2] * b[ 8] + a[ 3] * b[12];
	c[ 1] = a[ 0] * b[ 1] + a[ 1] * b[ 5] + a[ 2] * b[ 9] + a[ 3] * b[13];
	c[ 2] = a[ 0] * b[ 2] + a[ 1] * b[ 6] + a[ 2] * b[10] + a[ 3] * b[14];
	c[ 3] = a[ 0] * b[ 3] + a[ 1] * b[ 7] + a[ 2] * b[11] + a[ 3] * b[15];
	c[ 4] = a[ 4] * b[ 0] + a[ 5] * b[ 4] + a[ 6] * b[ 8] + a[ 7] * b[12];
	c[ 5] = a[ 4] * b[ 1] + a[ 5] * b[ 5] + a[ 6] * b[ 9] + a[ 7] * b[13];
	c[ 6] = a[ 4] * b[ 2] + a[ 5] * b[ 6] + a[ 6] * b[10] + a[ 7] * b[14];
	c[ 7] = a[ 4] * b[ 3] + a[ 5] * b[ 7] + a[ 6] * b[11] + a[ 7] * b[15];
	c[ 8] = a[ 8] * b[ 0] + a[ 9] * b[ 4] + a[10] * b[ 8] + a[11] * b[12];
	c[ 9] = a[ 8] * b[ 1] + a[ 9] * b[ 5] + a[10] * b[ 9] + a[11] * b[13];
	c[10] = a[ 8] * b[ 2] + a[ 9] * b[ 6] + a[10] * b[10] + a[11] * b[14];
	c[11] = a[ 8] * b[ 3] + a[ 9] * b[ 7] + a[10] * b[11] + a[11] * b[15];
	c[12] = a[12] * b[ 0] + a[13] * b[ 4] + a[14] * b[ 8] + a[15] * b[12];
	c[13] = a[12] * b[ 1] + a[13] * b[ 5] + a[14] * b[ 9] + a[15] * b[13];
	c[14] = a[12] * b[ 2] + a[13] * b[ 6] + a[14] * b[10] + a[15] * b[14];
	c[15] = a[12] * b[ 3] + a[13] * b[ 7] + a[14] * b[11] + a[15] * b[15];
	for (unsigned register char i = 0; i < 16; ++i) {
		a[i] = c[i];
	}
}

static void Matrix4::Perspective (float fovy, float aspect, float znear, float zfar) {
	Matrix4& mtx = *(new Matrix4);
	float f = 1.0f / tanf(fovy * c_PI / 360.0f);
	float A = (zfar + znear) / (znear - zfar);
	float B = (2.0f * zfar * znear) / (znear - zfar);
	mtx[ 0] = f / aspect ;
	mtx[ 5] = f          ;
    mtx[10] = A          ;
    mtx[11] = B          ;
    mtx[14] = -1.0f      ; 
    mtx[15] = 0          ;
    return mtx
}

static void Matrix4::Translate(Vector3& vec) {
		Matrix4& mtx = *(new Matrix4);
		a[ 3] = vec.x;
		a[ 7] = vec.y;
		a[11] = vec.z;
}

float* catrix4::getPtr() {
	return a;
}

