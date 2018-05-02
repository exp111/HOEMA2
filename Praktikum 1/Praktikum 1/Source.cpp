#include <iostream>
#include "CMyVektor.h"

double f(CMyVektor x){
	return (sin(x.getComponent(0) + pow(x.getComponent(1), 2)) + pow(x.getComponent(1), 3) - 6 * pow(x.getComponent(1), 2) + 9 * x.getComponent(1));
}

double g(CMyVektor x) {
	return -(2*pow(x.getComponent(0),2) - 2*(x.getComponent(0) * x.getComponent(1))+ pow(x.getComponent(2),2) + pow(x.getComponent(2), 2) - 2*x.getComponent(0) - 4*x.getComponent(2));
}

double test(CMyVektor x) {
	return pow(x.getComponent(0), 2);
}


CMyVektor setComponents(CMyVektor a, std::vector<double> b) {

	for (int i = 0; i <= a.getDimension(); i++) {
		a.setComponent(i, b[i]);
	}
	return a;
}


void gradientenverfahren(CMyVektor x, double(*f)(CMyVektor x), double lambda = 1.0) {

	CMyVektor xNeu  =	x + lambda * x.gradient(x, f);
	int c = 0;
	double check = f(xNeu);
	if (check < 0)
		check = check * (-1);
	double q = pow(10, -5);

	while(c < 50 || check < q){
		std::cout << "Schritt " << c << std::endl;
		std::cout << "x =";
		x.print();
		std::cout << "lambda " << lambda << std::endl;
		std::cout << " f(x) = " << f(x) << std::endl;
		std::cout << " grad f(x) = ";
		x.gradient(x, f).print();
		std::cout << std::endl;

		std::cout << "xNeu =";
		xNeu.print();
		std::cout << " f(x_neu) = " << f(xNeu) << std::endl;



		if (f(xNeu) > f(x)) {
			CMyVektor xTest = x + (2 * lambda *  x.gradient(x, f));
			std::cout << "Test mit doppelter Schrittweite "<< lambda << std::endl;
			std::cout << "xTest =";
			xTest.print();			
			std::cout << " f(x_Test) = " << f(xTest) << std::endl;

			if (f(xTest) > f(xNeu)) {
				x = xTest;
				lambda = lambda * 2;
				std::cout << "Verdoppeln!" << std::endl;
			}
			else
				x = xNeu;
		}
		else if (f(xNeu) <= f(x)) {

			while (f(xNeu) <= f(x)) {
				lambda = lambda / 2;
				xNeu = xNeu +  lambda *  xNeu.gradient(xNeu, f);
			}
			std::cout << "Halbieren! lambda : " << lambda << std::endl;
			x = xNeu;
		}
		c++;
		std::cout << std::endl;
	}

	
}



int main() {

	std::vector<double> t = {3,2};
	CMyVektor m =  CMyVektor(2, t);
	gradientenverfahren(m, &f);
	
	system("Pause");
	return 0;
}