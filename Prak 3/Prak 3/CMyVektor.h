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
	int getDimension() { return this->dimension; }
	void setDimension(int newDimension) { this->dimension = newDimension; }
	double getComponent(int n);
	void setComponent(int n, double newComponent);
	CMyVektor gradient(double(*funktion)(CMyVektor x));
	void print();
	double length();
	CMyVektor operator+(CMyVektor b);
	CMyVektor operator*(double lambda);

	//CMyVektor operator*(CMyVektor b);
	double& operator[](int i);
	double operator()(int i);
};

