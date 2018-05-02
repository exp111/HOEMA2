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

CMyVektor CMyVektor::gradient(CMyVektor x, double(*funktion)(CMyVektor x)) {

	double h = pow(10, -8);
	double r = 0.0;
	CMyVektor gradient = CMyVektor(x.getDimension());
	for (int i = 0; i < x.getDimension();  i++) {
		double temp = x.getComponent(i);
		x.setComponent(i,temp + h) ;

		gradient.setComponent(i, ((funktion(x) + h) - funktion(x)) / h);
		x.setComponent(i, temp );
	}

	return gradient;
}

void CMyVektor::print() {
	
	std::cout << "( ";
	for (int i = 0; i < this->dimension; i++)
		std::cout << this->getComponent(i) << " ;";
	std::cout << ")" << std::endl;
}

CMyVektor operator +(CMyVektor a, CMyVektor b) {

	int dimension_a = a.getDimension();
	std::vector<double> resultVektor;
	for (int i = 0; i < dimension_a; i++)
		resultVektor.push_back(0);

	if (dimension_a != b.getDimension())
		return b;

	for (int i = 0; i < dimension_a; i++) 
		resultVektor[i] = a.getComponent(i) + b.getComponent(i);	

	return CMyVektor(dimension_a, resultVektor);
}

CMyVektor operator *(double lambda, CMyVektor a) {

	for (int i = 0; i < a.getDimension(); i++)
		a.setComponent(i, a.getComponent(i) * lambda);

		return a;
}

