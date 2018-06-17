#include <vector>
#include "CMyVektor.h"
#include "CKomplex.h"
#include "functions.h"


int main() {

	std::vector<CKomplex> blyat;
	blyat.push_back(CKomplex(2,0));
	blyat.push_back(CKomplex(1, 0));
	blyat.push_back(CKomplex(2, 0));
	blyat.push_back(CKomplex(-1, 0));
	std::vector<CKomplex> in = werte_einlesen("./Daten_original.txt");
	fourier b = fourierTransForwards(in);
	std::vector<CKomplex> out =fourierTransBackwards(b, 1000);
	std::cout << difference(in, out) << std::endl;
	werte_ausgeben("./asd.txt", out, 1);
	system("PAUSE");
	return 0;
}



