#include "CMyVektor.h"


double CMyVektor::getComponent(int n) {
	if (this->components.size() >= n)
		return this->components[n];
}
void CMyVektor::setComponent(int n, double newComponent) {
	if (this->components.size() >= n)
		this->components[n] = newComponent;
}
/*
CMyVektor::CMyVektor(const CMyVektor &a) {

this->setDimension(a.getDimension());
for (int i = 0; i <= a.getDimension(); i++)
this->setComponent(i,a.getComponent(i));


}
*/

double CMyVektor::length() {
	double l = 0.0;
	double result = 0.0;
	for (int i = 0; i < dimension; i++) {
		double powed = pow(this->getComponent(i), 2);
		result += powed;
	}
	return sqrt(result);

}

CMyVektor CMyVektor::gradient(double(*funktion)(CMyVektor x)) {

	double h = pow(10, -8);
	double r = 0.0;
	CMyVektor gradient = CMyVektor(this->getDimension());
	for (int i = 0; i < this->getDimension(); i++) {
		double temp = this->getComponent(i);
		double preset = (funktion(*this));
		this->setComponent(i, temp + h);

		gradient.setComponent(i, ((funktion(*this)) - preset) / h);
		this->setComponent(i, temp);
	}

	return gradient;
}

void CMyVektor::print() {

	std::cout << "( ";
	for (int i = 0; i < this->dimension; i++)
		std::cout << this->getComponent(i) << " ;";
	std::cout << ")" << std::endl;
}

CMyVektor CMyVektor::operator +(CMyVektor b) {

	int dimension_a = this->getDimension();
	std::vector<double> resultVektor;
	for (int i = 0; i < dimension_a; i++)
		resultVektor.push_back(0);

	if (dimension_a != b.getDimension())
		return b;

	for (int i = 0; i < dimension_a; i++)
		resultVektor[i] = this->getComponent(i) + b.getComponent(i);

	return CMyVektor(dimension_a, resultVektor);
}


double& CMyVektor::operator [](int i) {
	return this->components[i];
}

double CMyVektor::operator ()(int i) {
	return this->getComponent(i);
}

CMyVektor CMyVektor::operator *(double lambda) {

	for (int i = 0; i < this->getDimension(); i++)
		this->setComponent(i, this->getComponent(i) * lambda);

	return *this;
}
/*
double CMyVektor::operator *(CMyVektor b) {

double result = 0.0;
for (int i = 0; i < this->getDimension(); i++)



return result;
}
*/
