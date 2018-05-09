#pragma once
#include "CMyVektor.h"


class CMyMatrix {
private:
	int dimension_x = 0, dimension_y = 0;
	std::vector<CMyVektor> components;
	
public:
	CMyMatrix(int new_dim_x, int new_dim_y);
	void setComponent(int x, int y, double newComp) { this->components[x][y] = newComp; }
	double getComponent(int x, int y) { return this->components[x][y]; }
	void setDimensions(int new_dim_x, int new_dim_y) { this->dimension_x = new_dim_x; this->dimension_y = new_dim_y; }
	void setDimensionX(int new_dim_x) { this->dimension_x = new_dim_x; }
	void setDimensionY(int new_dim_y) {this->dimension_y = new_dim_y; }
	int getDimensionX() { return this->dimension_x; }
	int getDimensionY() { return this->dimension_y; }
	CMyMatrix invers();
	double operator()(int x, int y) { return getComponent(x, y); }
	CMyVektor& operator[](int x) { return this->components[x]; }
	
};
