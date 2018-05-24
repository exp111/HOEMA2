#include "CMyMatrix.h"
#include <iomanip>

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
	double det = 1 / ((a*d) - (b*c));
	if(det == 0)
		throw std::invalid_argument("Matrix nicht invertierbar, da det == 0");

	CMyMatrix tmp(x, y);
	

	tmp[0][0] = d * det;
	tmp[0][1] = (b * (-1) ) * det;
	tmp[1][0] = (c * (-1)) * det;
	tmp[1][1] = a * det;
	return tmp;
}


void newtonVerfahren(CMyVektor x, CMyVektor(*f)(CMyVektor x)) {


	for (int i = 0; i < 50; i++) {
		std::cout << "Schritt " << i << std::endl;
		if (f(x).length() < 1e-5) {
			std::cout << std::setw(8) << "" << "Abgebrochen aufgrund der laenge" << std::endl;
			return;
		}
		std::cout << std::setw(8) << "" << "x = ";
		x.print();
		std::cout << std::setw(8) << "" << "f(x) = ";
		f(x).print();

		CMyMatrix deriv = jacobi(x, f);
		CMyMatrix inverse = deriv.invers();

		std::cout << std::setw(8)<< "" << "f'(x) = ";
		deriv[0].print();
		std::cout << std::setw(8) << "";
		deriv[1].print();

		std::cout << std::setw(8) << "" << "f'(x)^(-1) = ";
		inverse[0].print();
		std::cout << std::setw(8) << "";
		inverse[1].print();

		CMyVektor val = inverse * f(x) * (-1);

		std::cout << std::setw(8) << "" << "dx = ";
		val.print();
		std::cout << std::setw(8) << "" << "||f(x)|| = " << f(x).length() << std::endl;
		x = val + x;
		std::cout << std::endl;
	}

}

CMyMatrix jacobi(CMyVektor x, CMyVektor(*f)(CMyVektor x)) {

	int x_len = x.getDimension();
	int y_len = f(x).getDimension();

	CMyMatrix jacobiMatrix(x_len, y_len);
	const double h = 1e-4;
	double r = 0.0;
	CMyVektor gradient = CMyVektor(x_len);

	for (int yA = 0; yA < y_len; yA++) {
		for (int xA = 0; xA < x_len; xA++) {
			double temp = x(xA);
			double preset = f(x)(yA);
			x[xA] = temp + h;

			gradient[xA] = (f(x)(yA) - preset) / h;
			x[xA] = temp;
		}
		jacobiMatrix[yA] = gradient;
	}
	return jacobiMatrix;
}