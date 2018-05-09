#pragma once
#include <map>
#include <vector>


class CMyMatrix {
private:
	int dimension;
	std::map<double, std::vector<double>> components;
public:
	CMyMatrix(int newDim) : dimension(newDim) {}
	void setComponent(int x, int y, double newComp);
	double getComponent(int x, int y, double newComp);
	CMyMatrix invers();
	


};