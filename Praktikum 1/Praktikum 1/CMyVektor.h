#pragma once
#include <iostream>
#include <vector>

class CMyVektor {

private:
	int dimension = 0;
	std::vector<double> components;
public:
	CMyVektor(int newDimension, std::vector<double> newComponents) : dimension(newDimension), components(newComponents) {};
	CMyVektor(int newDimension) : dimension(newDimension) {
		for (int i = 0; i < newDimension; i++)
			this->components.push_back(0);
	}
	//CMyVektor(const CMyVektor &a);
	int getDimension()  { return this->dimension; }
	void setDimension(int newDimension) { this->dimension = newDimension; }
	double getComponent(int n) ;
	void setComponent(int n, double newComponent);
	// get length components quadrieren und wurzeln
	CMyVektor gradient(CMyVektor x, double (*funktion )(CMyVektor x));
	void print();
	
	
};

CMyVektor operator+(CMyVektor a, CMyVektor b);
CMyVektor operator*(double lambda, CMyVektor a);