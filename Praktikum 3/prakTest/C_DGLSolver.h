#pragma once
#include"CMyVektor.h"

class C_DGLSolver
{
private:
	typedef CMyVektor(*f_DGL_system)(CMyVektor y, double x);
	typedef double(*f_DGL_nth_order)(CMyVektor y, double x);

	f_DGL_system fDGLSystem = nullptr;
	f_DGL_nth_order fDGLNthOrder = nullptr;

	bool isDGLHigherOrder = false;

	CMyVektor ableitungen(CMyVektor y, double x);
public:
	C_DGLSolver(CMyVektor(*f)(CMyVektor y, double x));
	C_DGLSolver(double(*f)(CMyVektor y, double x));

	CMyVektor eulerVerfahren(double xStart, double xEnd, double steps, CMyVektor yStart);
	CMyVektor heunVerfahren(double xStart, double xEnd, double steps, CMyVektor yStart);
};
