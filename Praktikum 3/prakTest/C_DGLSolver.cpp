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

	if (this->isDGLHigherOrder) {
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

void C_DGLSolver::eulerVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart) {}
void C_DGLSolver::heunVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart) {}