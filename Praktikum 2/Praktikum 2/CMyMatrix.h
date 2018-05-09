#pragma once
#include "CMyVektor.h"


class CMyMatrix {
private:
	int dimension;
	std::vector<CMyVektor> components;
	
public:
	CMyMatrix(int newDim) : dimension(newDim) {}
	void setComponent(int x, int y, double newComp) { this->components[x][y] = newComp; }
	double getComponent(int x, int y, double newComp) { return this->components[x][y]; }
	void setDimension(int newDimension) { this->dimension = newDimension; }
	int getDimension() { return this->dimension; }
	CMyMatrix invers();
	double operator()(int x, int y) { return getComponent(x, y); }
	//double& operator[](int x) { return this->components[x]; }
	


};
