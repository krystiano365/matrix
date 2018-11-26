//
// Created by krystian on 25.11.18.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include<ostream>
#include "smart_ptr.h"
using namespace std;

class Matrix {
private:
	//double** array;
	smart_ptr<double*> array;
	unsigned int rows_no, columns_no;
	void allocate();

public:
	Matrix();
	Matrix(unsigned int rows, unsigned int columns);
	Matrix(unsigned int rows, unsigned int columns, double initVal);
	Matrix(const Matrix& m);
	~Matrix();

	Matrix& operator+= (const Matrix& m);
	Matrix& operator-= (const Matrix& m);
	Matrix& operator*= (const Matrix& m);
	Matrix& operator/= (const Matrix& m);

	Matrix& operator= (const Matrix& m);  //todo: spytać co powinno robić

	friend Matrix operator+ (const Matrix& m1, const Matrix& m2);
	friend ostream& operator<< (ostream& s, const Matrix& m);
};



struct DifferentSizesException : public exception {

public:
	auto what() {
		return "Couldn't add matrices: DifferentSizeException";
	}
};


#endif //MATRIX_MATRIX_H
