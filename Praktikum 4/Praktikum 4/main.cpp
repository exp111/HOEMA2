#include <vector>
#include "CMyVektor.h"
#include "CKomplex.h"
#include "functions.h"


int main() {

	std::vector<CKomplex> in = werte_einlesen("./Daten_original.txt");

	std::vector<CKomplex> orig = fourierComplex(in, true);
	werte_ausgeben("./test_orig.txt", orig);
	werte_ausgeben("./test_01.txt", orig, 0.1);
	werte_ausgeben("./test_1.txt", orig, 1.0);

	std::vector<CKomplex> original = werte_einlesen("./test_orig.txt");
	std::vector<CKomplex> epsilon01 = werte_einlesen("./test_01.txt");
	std::vector<CKomplex> epsilon1 = werte_einlesen("./test_1.txt");

	std::vector<CKomplex> outOrig = fourierComplex(original, false);
	std::vector<CKomplex> out01 = fourierComplex(epsilon01, false);
	std::vector<CKomplex> out1 = fourierComplex(epsilon1, false);


	std::cout << difference(in, out01) << std::endl;
	std::cout << difference(outOrig, out1) << std::endl;
	
	system("PAUSE");
	return 0;
}



