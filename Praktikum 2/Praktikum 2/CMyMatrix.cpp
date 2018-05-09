#include "CMyMatrix.h"

CMyMatrix::CMyMatrix(int dimx, int dimy) {
	this->dimension_x = dimension_x;
	this->dimension_y= dimension_y;
	for (int i = 0; i < dimx; i++)
		this->components.push_back(CMyVektor(dimension_y));
}

CMyMatrix CMyMatrix::invers() {
	int x = this->dimension_x;
	int y = this->dimension_y;
	if(x != 2 && y != 2 || x != 2 || y != 2)
		throw std::invalid_argument("Matrix kann nicht invertiert werden");

	double a = this->getComponent(0,0);
	double b = this->getComponent(0,1);
	double c = this->getComponent(1,0);
	double d = this->getComponent(1,1);

	double detInverse = ((a*d)-(b*c))/1;
	this[0][0] = d * detInverse;
	this[0][1] = (b * (-1) ) * detInverse;
	this[1][0] = (c * (-1)) * detInverse;
	this[1][1] = a * detInverse;
}

