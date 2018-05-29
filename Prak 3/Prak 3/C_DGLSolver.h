#pragma once
#include "CMyVektor.h"

class C_DGLSolver
{
private:
	typedef CMyVektor (*f_DGL_System)(CMyVektor y, double x);
	typedef double(*f_DGL_nterOrdnung)(CMyVektor y, double x);


public:
	C_DGLSolver();
	~C_DGLSolver();
	CMyVektor ableitungen(CMyVektor y, double x);

};

