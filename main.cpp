#include <iostream>
#include "Matrix.h"

int main() {

//	Matrix matrix1(2, 2, 7);
//	Matrix matrix2;
//	Matrix matrix3(2, 2, 2);
//	cout << "matrix1:\n" << matrix1;
//	cout << "matrix2:\n" << matrix2;
//	cout << "matrix3:\n" << matrix3;
//
//	matrix2 = matrix1;
//
////	cout << "references to matrix1 = " << matrix1.getReferences() << endl;
//
//	try {
//		matrix3 += matrix2;
//		cout << "matrix3:\n" << matrix3;
//	} catch (DifferentSizesException &e) {
//		cout << e.what();
//	}
//
//	cout << "matrix1:\n" << matrix1;
//
//	try {
//		matrix3 *= matrix1;
//		cout << "matrix3:\n" << matrix3;
//	} catch (DifferentSizesException &e) {
//		cout << e.what();
//	}

	Matrix matrixFromFile("/home/krystian/Desktop/matrix.txt");
	//Matrix matrixFromFile2("matrix.txt");

	return 0;
}