#include <iostream>
#include "MaterialMatrix.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	MaterialMatrix matrix(2, 2);
	matrix.loadMatrixFromFile("Matrix.txt");
	matrix.printMatrix();
	return 0;
}