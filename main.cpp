#include <iostream>
#include "Matrix.h"

int main() {

	Matrix matrix1(10, 12, 7);
	Matrix matrix2;
	Matrix matrix3(1, 1, 1);
	cout << "matrix1:\n" << matrix1;
	cout << "matrix2:\n" << matrix2;
	cout << "matrix3:\n" << matrix3;

	matrix2 = matrix1;
	Matrix m;
	m = matrix2;
	cout << "references to matrix1 = " << matrix1.getReferences() << endl;

	cout << "matrix1:\n" << matrix1;

	matrix2 += matrix2;

	cout << "references to matrix1 = " << matrix1.getReferences() << endl;

	cout << "matrix1:\n" << matrix1;
	cout << "matrix2:\n" << matrix2;
//	try {
//		Matrix matrix3(matrix1 += matrix2);
//		cout << "matrix3:\n" << matrix3;
//	} catch (DifferentSizesException &e) {
//		cout << e.what();
//	}





	return 0;
}