#include <iostream>
#include "Matrix.h"

int main() {

	Matrix matrix1(10, 12);
	Matrix matrix2(10, 12, 7);
	cout << "matrix1:\n" << matrix1;
	cout << "matrix2:\n" << matrix2;
	Matrix matrix3(matrix1 += matrix2);
	cout << "matrix3:\n" << matrix3;
	return 0;
}