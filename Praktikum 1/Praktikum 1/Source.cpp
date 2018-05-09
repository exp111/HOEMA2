#include <iostream>
#include "CMyVektor.h"

double f(CMyVektor x){
	return (sin(x(0) + pow(x(1), 2)) + pow(x(1), 3) - 6 * pow(x(1), 2) + 9 * x(1));
}

double g(CMyVektor x) {
	return -(2*pow(x(0),2) - 2*(x(0) * x(1))+ pow(x(1),2) + pow(x(2), 2) - 2*x(0) - 4*x(2));
}

double test(CMyVektor x) {
	return pow(x(0), 2);
}


CMyVektor setComponents(CMyVektor a, std::vector<double> b) {

	for (int i = 0; i <= a.getDimension(); i++) {
		a[i] = b[i];
	}
	return a;
}

void gradientenverfahren(CMyVektor x, double(*f)(CMyVektor x), double lambda = 1.0) {

	CMyVektor xNeu = CMyVektor(x.getDimension());
	double c = pow(10, -5);

	for (int i = 0; i <= 49; i++) {
		xNeu = x +  x.gradient(f) * lambda;

		std::cout << "Schritt " << i << std::endl;
		std::cout << "x =";
		x.print();
		std::cout << "lambda " << lambda << std::endl;
		std::cout << " f(x) = " << f(x) << std::endl;
		std::cout << " grad f(x) = ";
		x.gradient( f).print();
		std::cout << " ||grad f(x)|| = " << x.gradient( f).length() << std::endl;

		std::cout << "xNeu =";
		xNeu.print();
		std::cout << " f(x_neu) = " << f(xNeu) << std::endl;

		if (x.gradient( f).length() < c) {
			std::cout << "Abgebrochen aufgrund der Laenge" << std::endl;
			return;
		}

		if (f(xNeu) > f(x)) {
			CMyVektor xTest = x + (x.gradient( f) * lambda * 2);
			if (f(xTest)> f(xNeu)) {
				lambda *= 2;
				x = xTest;
			}
			else {
				x = xNeu;
				continue;
			}
		} 
		else if (f(xNeu) <= f(x)) {
			CMyVektor xTest = xNeu;
			while (f(x) > f(xTest)) {
				lambda /= 2;
				xTest = x +  x.gradient( f) * lambda;
			}
			x = xTest;
		}
		std::cout << std::endl;
	}
}


int main() {
	
	int selection = 0;
	std::vector<double> a = { 3,2 };
	CMyVektor vA =  CMyVektor(2, a);
	a = { 0,0,0 };
	CMyVektor vB = CMyVektor(3, a);

	while (selection != 3) {
		
		std::cout << "1 fuer f, 2 fuer g" << std::endl;
		std::cin >> selection;
		switch (selection) {
		case 1:
			gradientenverfahren(vA, &f);
			break;
		case 2:
			gradientenverfahren(vB, &g, 0.1);
			break;
		}	
	
	}
	
	return 0;
}