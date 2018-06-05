#include "C_DGLSolver.h"

C_DGLSolver::C_DGLSolver(CMyVektor(*f)(CMyVektor y, double x)) {
	this->fDGLSystem = f;
	this->isDGLHigherOrder = false;

}

C_DGLSolver::C_DGLSolver(double(*f)(CMyVektor y, double x)) {
	this->fDGLNthOrder = f;
	this->isDGLHigherOrder = true;
}

CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x) {

	if (!this->isDGLHigherOrder) {
		return this->fDGLSystem(y, x);
	}
	else {
		CMyVektor dgl(y.getDimension());
		int lastEntry = y.getDimension() - 1;
		dgl[lastEntry] = this->fDGLNthOrder(y, x);
		
		for (int i = 0; i < lastEntry; i++) {
			dgl[i] = y(i + 1);
		}
		return dgl;
	}
}

void C_DGLSolver::eulerVerfahren(double xStart, double xEnd, double steps, CMyVektor yStart) {

	double h = (xEnd - xStart) / steps;
	double x = xStart;
	CMyVektor y = yStart;

	for (double i = 0; x < xEnd; i++,x += h) {
		std::cout << std::endl;
		std::cout << "Schritt " << i << ":" << std::endl;
		std::cout << "x = " << x << std::endl;
		std::cout << "y = ";
		y.print();
		std::cout << std::endl;
		CMyVektor yStrich = ableitungen(y, x);
		std::cout << "y' = ";
		yStrich.print();
		std::cout << std::endl;
		y = y + yStrich * h;
	}

}
void C_DGLSolver::heunVerfahren(double xStart, double xEnd, double steps, CMyVektor yStart) {
		
	double h = (xEnd - xStart) / steps;
	double x = xStart;
	CMyVektor y = yStart;

	std::cout << "h = " << h << std::endl;

	for (int i = 0; x < xEnd; i++, x += h) {

		std::cout << "Schritt " << i << ":" << std::endl;
		std::cout << "x = " << x << std::endl;
		CMyVektor yDeriv = ableitungen(y, x);
		std::cout << "y = ";
		y.print();
		std::cout << "y'_orig = ";
		yDeriv.print();
		/////////////////////////////////
		CMyVektor yOrigDeriv = yDeriv;
		CMyVektor yTest = y + yDeriv * h;
		std::cout << "y_Test = ";
		yTest.print();
		double xNext = x + h;
		CMyVektor yTestDeriv = ableitungen(yTest, xNext);

		std::cout << "y'_Test = ";
		yTestDeriv.print();
		//////////////////////////////////////////////////
		CMyVektor yMiddle = (yOrigDeriv + yTestDeriv) * 0.5;

		std::cout << "y'_Mittel = ";
		yMiddle.print();

		y = (y + yMiddle * h) ;
		std::cout << std::endl;

	}

}

