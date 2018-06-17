#include <fstream>   
#include <vector>
#include "CKomplex.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "functions.h"



std::vector<CKomplex>  werte_einlesen(const char *dateiname)
{
	int i, N, idx;
	double re, im;
	std::vector<CKomplex> werte;
	// File oeffnen
	std::ifstream fp;
	fp.open(dateiname);
	// Dimension einlesen
	fp >> N;
	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i<N; i++)
		werte[i] = null;
	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}
	// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const char *dateiname, std::vector<CKomplex> werte, double epsilon)
{
	int i;
	int N = werte.size();
	// File oeffnen
	std::ofstream fp;
	fp.open(dateiname);
	// Dimension in das File schreiben
	fp << N << std::endl;
	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++) 
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].re() << "\t" << werte[i].im() << std::endl;
	
	// File schliessen
	fp.close();
}


double xAt(int i, int n) {
	return (2 * M_PI * i) / n;
}


//true hin richtung , false  rueckrichtung
fourier fourierTransForwards(std::vector<CKomplex> data) {

	int n = data.size();
	int nHalf = n / 2;
	std::vector<double> resultA, resultB;
	double aX = 0, bX = 0;

	for (int a = 0; a < n - 1; a++) {
		bool setB = a <= nHalf - 1 && a > 0;
		aX = 0; bX = 0;
		for (int i = 0; i < n; i++) {

			aX += data[i].re() * cos(a * xAt(i, n));

			if (setB) {
				bX += data[i].re() * sin(a * xAt(i, n));
			}

		}

		if (setB) resultB.push_back((bX * 2) / n);

		resultA.push_back((aX * 2) / n);
	}
	return fourier(resultA, resultB);
}



std::vector<CKomplex> fourierTransBackwards(fourier data, int n) {
	
	std::vector<CKomplex> resultF;
	
	for (int f = 0; f < n; f++) {
		double fK = data._a[0] / 2;
		for (int i = 1; i <= (n / 2) - 1; i++) {

			fK += data._a[i] * cos( xAt(f, n));
			fK += data._b[i-1] * sin( xAt(f, n));
			fK += (data._a[n / 2] / 2) * cos(2 * xAt(f, n));
		}
		resultF.push_back(CKomplex(fK,0));
	}

	return resultF;
}

double difference(std::vector<CKomplex> in, std::vector<CKomplex> out) {

	double diff = 0;
	for (int i = 0; i < out.size(); i++) {

		double curr = in[i].abs() - out[i].abs();
		if (curr > diff && out[i].abs() != 0)
			diff = curr;
	}
	return diff;
}

std::vector<CKomplex> fourierComplex(std::vector<CKomplex> data,bool direction) {

	int n = data.size();
	std::vector<CKomplex> result;

	if (direction) {
		for (int h = 0; h < n; h++) {
			result.push_back(CKomplex(0, 0));
			for (int k = 0; k < n  ; k++) {
				result[h] += data[k] * CKomplex((-2 * M_PI * k * h)/n);
			}
			result[h] *= 1 / sqrt(n);
		}
	}
	else {
		for (int h = 0; h < n; h++) {
			result.push_back(CKomplex(0, 0));
			for (int k = 0; k < n ; k++) {
				result[h] += data[k] * CKomplex((2 * M_PI * k * h)/n);
			}
			result[h] *= 1 / sqrt(n);
		}
	
	}

	return result;
}