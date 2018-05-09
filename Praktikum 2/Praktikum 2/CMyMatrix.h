#pragma once
#include "CMyVektor.h"


class CMyMatrix {
private:
	int dimension_x = 0, dimension_y = 0;
	std::vector<CMyVektor> components;
	
public:
	CMyMatrix(int new_dim_x, int new_dim_y);
	void setComponent(int y, int x, double newComp) { this->components[y][x] = newComp; }
	double getComponent(int y, int x) { return this->components[y][x]; }
	void setDimensions(int new_dim_x, int new_dim_y) { this->dimension_x = new_dim_x; this->dimension_y = new_dim_y; }
	void setDimensionX(int new_dim_x) { this->dimension_x = new_dim_x; }
	void setDimensionY(int new_dim_y) {this->dimension_y = new_dim_y; }
	int getDimensionX() { return this->dimension_x; }
	int getDimensionY() { return this->dimension_y; }
	CMyMatrix invers();
	double operator()(int y, int x) { return getComponent(y, x); }
	CMyVektor& operator[](int y) { return this->components[y]; }
	CMyVektor operator *(CMyVektor b);
	
};
