#include "CKomplex.h"

CKomplex::CKomplex() {
	this->real = 0;
	this->imagi = 0;
}

CKomplex::CKomplex(double a, double b) {
	this->real = a;
	this->imagi = b;
}

CKomplex::CKomplex(double phi) {
	this->real = cos(phi);
	this->imagi = sin(phi);
}

double CKomplex::abs() {
	return sqrt(re()*re() + im() * im());	
}

CKomplex CKomplex::operator +(CKomplex r) {
	double newReal = this->real + r.re();
	double newImagi = this->imagi + r.im();
	return CKomplex(newReal, newImagi);
}

void CKomplex::operator +=(CKomplex r) {
	*this = *this + r;
}

CKomplex CKomplex::operator *(CKomplex r) {
	double newReal = (this->re() * r.re()) + (this->im() * r.im());
	double newImag = (this->re() * r.im()) + (this->im() * r.re());
	return CKomplex(newReal, newImag);
}

CKomplex CKomplex::operator *(double r) {
	double newReal = this->real * r;
	double newImagi = this->imagi * r;
	return CKomplex(newReal,newImagi);
}

void CKomplex::operator *=(double r) {
	*this = *this * r;
}