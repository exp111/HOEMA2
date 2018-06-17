#include <fstream>   
#include <vector>
#include "CKomplex.h"
#define _USE_MATH_DEFINES
#include <math.h>

struct fourier {
	std::vector<double> _a;
	std::vector<double> _b;

	fourier() {}
	fourier(std::vector<double> a, std::vector<double> b) {
		_a = a;
		_b = b;
	}
};

std::vector<CKomplex>  werte_einlesen(const char *dateiname);
void werte_ausgeben(const char *dateiname, std::vector<CKomplex> werte, double epsilon = -1);
double xAt(int i, int n);
fourier fourierTransForwards(std::vector<CKomplex> data);
std::vector<CKomplex> fourierTransBackwards(fourier data, int n);
std::vector<CKomplex> fourierComplex(std::vector<CKomplex> data,bool direction);
double difference(std::vector<CKomplex> in, std::vector<CKomplex> out);
