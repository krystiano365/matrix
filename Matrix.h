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

	int getReferences();
	//Matrix& perfectCopy(const Matrix& m);
	Matrix& clone();
	Matrix& operator+= (const Matrix& m);
	Matrix& operator-= (const Matrix& m);
	Matrix& operator*= (const Matrix& m);
	Matrix& operator/= (const Matrix& m);

	Matrix& operator= (const Matrix& m) = default;

	friend Matrix operator+ (const Matrix& m1, const Matrix& m2);
	friend ostream& operator<< (ostream& s, const Matrix& m);
};





// =====================================================================================================================EXCEPTIONS


class DifferentSizesException : public exception { };

class AdditionDifferentSizesException : public DifferentSizesException {
public:
	const char* what() const noexcept override {
		return "Unable to add matrices: both matrices must have equal sizes";
	}
};

class MultiplicationDifferentSizesException : public DifferentSizesException {
public:
	const char* what() const noexcept override {
		return "Unable to multiply matrices: first matrix's COLUMNS NUMBER must be equal to the second matrix's ROWS "
		 "NUMBER";
	}
};


#endif //MATRIX_MATRIX_H
