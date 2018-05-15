#include "CMyMatrix.h"

CMyMatrix::CMyMatrix(int dimx, int dimy) {
	this->dimension_x = dimx;
	this->dimension_y= dimy;
	for (int i = 0; i < dimy; i++)
		this->components.push_back(CMyVektor(dimx));
}

CMyVektor CMyMatrix::operator *(CMyVektor b) {
	
	CMyVektor tmp = CMyVektor(this->getDimensionX());
	double result = 0;
	for (int y = 0; y < this->dimension_y; y++) {
		result = 0.0;
		for (int x = 0; x < this->dimension_x; x++) {
			 result += this->getComponent(y,x) * b(x);
		}
		tmp[y] = result;
	}
	return tmp;
}

CMyMatrix CMyMatrix::invers() {
	int x = this->dimension_x;
	int y = this->dimension_y;
	if(x != 2 || y != 2 )
		throw std::invalid_argument("Matrix kann nicht invertiert werden");

	double a = this->getComponent(0,0);
	double b = this->getComponent(0,1);
	double c = this->getComponent(1,0);
	double d = this->getComponent(1,1);

	CMyMatrix tmp(x, y);
	double detInverse = 1/((a*d)-(b*c));

	tmp[0][0] = d * detInverse;
	tmp[0][1] = (b * (-1) ) * detInverse;
	tmp[1][0] = (c * (-1)) * detInverse;
	tmp[1][1] = a * detInverse;
	return tmp;
}

