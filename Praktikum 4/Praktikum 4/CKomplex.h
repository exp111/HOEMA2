#pragma once
#include <iostream>
#include <math.h>

class CKomplex {
private:
	double real, imagi;
public:
	CKomplex();
	CKomplex(double a, double b);
	CKomplex(double phi);

	double re() { return this->real; }
	double im() { return this->imagi; }
	double abs();

	CKomplex operator +(CKomplex r);
	void operator +=(CKomplex r);
	CKomplex operator *(CKomplex r);
	CKomplex operator *(double r);
	void operator *=(double r);
	


};