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
		
	}
}

void C_DGLSolver::eulerVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart) {}
void C_DGLSolver::heunVerfahren(int xStart, int xEnd, int schritte, CMyVektor yStart) {}