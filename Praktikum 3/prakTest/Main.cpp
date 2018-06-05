#include "C_DGLSolver.h"



CMyVektor yFirstOrder(CMyVektor y, double x) {
	CMyVektor first(2);
	first[0] = (2 * y[1]) - (x * y[0]);
	first[1] = (y[0] * y[1]) - (2 * pow(x, 3));
	return first;
}

double yThirdOrder(CMyVektor y, double x) {
	return (2 * x * y[1] * y[2])+(2 * y[0] * y[0] * y[1]);
}


void userInput(int &selection){

	std::cout << "1. erster Ordnung Euler" << std::endl;
	std::cout << "2. erster Ordnung Heun" << std::endl;
	std::cout << "3. Hoeherer Ordnung Euler" << std::endl;
	std::cout << "4. Hoeherer Ordnung Heun" << std::endl;
	std::cout << "5. Beenden" << std::endl;
	std::cin >> selection;
}

void inputSteps(int &steps){
	
	std::cout << "Angabe der Schrittanzahl" << std::endl;
	std::cin >> steps;
}


int main() {

	int selection = 0,steps = 0;
	C_DGLSolver DGLFirst(yFirstOrder);
	C_DGLSolver DGLHigher(yThirdOrder);
	CMyVektor startFirst(2);
	startFirst[0] = 0; startFirst[1] = 1;
	CMyVektor startHigher(3);
	startHigher[0] = 1; startHigher[1] = -1; startHigher[2] = 2;

	while(selection != 5){
	
		 userInput(selection);
		
		switch (selection) {
		case 1:
			DGLFirst.eulerVerfahren(0, 2, 100, startFirst);
			break;
		case 2:
			DGLFirst.heunVerfahren(0, 2, 100, startFirst);
			break;
		case 3:
			inputSteps(steps);
			DGLHigher.eulerVerfahren(0, 2, steps, startHigher);
			break;
		case 4:
			inputSteps(steps);
			DGLHigher.heunVerfahren(0, 2, steps, startHigher);
			break;
		default:
			break;
		}


	}

	return 0;
}