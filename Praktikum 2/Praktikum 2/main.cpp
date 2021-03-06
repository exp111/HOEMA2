#include "CMyMatrix.h"

CMyVektor f(CMyVektor x) {

	CMyVektor func(3);
		func[0] = x(0)*x(1)*exp(x(2));
		func[1] = x(1)*x(2)*x(3);
		func[2] = x(3);
	
	return func;
}

CMyVektor g(CMyVektor x) {

	CMyVektor func(2);
	func[0] = (pow(x(0), 3)*pow(x(1), 3)) - 2 * x(1);
	func[1] = x(0)-2;
	return func;
}


/*
CMyVektor fZusatz(CMyVektor x) {
	return (sin(x(0) + pow(x(1), 2)) + pow(x(1), 3) - 6 * pow(x(1), 2) + 9 * x(1));
}
*/
CMyVektor fZusatz(CMyVektor x) {

	CMyVektor f(2);
	f[0] = cos(x(0) + pow(x(1), 2));
	f[1] = cos(x(0) + pow(x(1), 2)) * 2 * x(1) + 3 * pow(x(1),2) - 12* x(1) + 9;
	return f;
}









void newtonExtremStelle(CMyVektor x, CMyVektor(*f)(CMyVektor x)) {
	const double stop = 0.00001;

	for (int i = 0; i < 50; i++) {
		std::cout << "Schritt " << i << std::endl;
		if (f(x).length() < stop) {
			std::cout << "Abgebrochen aufgrund der laenge" << std::endl;
			return;
		}
		std::cout << "x = ";
		x.print();
		std::cout << "f(x) = ";
		f(x).print();

		CMyMatrix deriv = jacobi(x, f);
		CMyMatrix inverse = deriv.invers();

		std::cout << "f'(x) = ";
		deriv[0].print();
		deriv[1].print();

		std::cout << "f'(x)^(-1) = ";
		inverse[0].print();
		inverse[1].print();

		CMyVektor val = inverse * f(x) * (-1);


		std::cout << "dx = ";
		val.print();
		std::cout << "||f(x)|| = " << f(x).length() << std::endl;
		x = val + x;
	}

}


int main() {

	CMyMatrix t(4,3);
	CMyVektor zusatz1(2), newton(2), jacob(4);
	zusatz1[0] = 3; zusatz1[1] = 2;
	newton[0] = 1;	newton[1] = 1;
	jacob[0] = 1; jacob[1] = 2; 
	jacob[2] = 0; jacob[3] = 3;
	int selection = 0;
	while (selection != 4) {
		std::cout << "test 0, newton 1, zusatz 2" << std::endl;
		std::cin >> selection;

		switch (selection) {
		case 0:
			 t = jacobi(jacob, &f);
			 t[0].print();
			 t[1].print();
			 t[2].print();			
			break;
		case 1:			
			newtonVerfahren(newton, &g);
			break;
		case 2:
			newtonVerfahren(zusatz1, &fZusatz);
			//zusatz_jacobi();
			//newtonExtremStelle(zusatz1, &fZusatz);
			break;
		}
	
	}
	return 0;
}