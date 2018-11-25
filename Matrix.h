//
// Created by krystian on 25.11.18.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include<ostream>
using namespace std;

class Matrix {
private:
	double** array;
	unsigned int rows_no, columns_no;
	void allocate();

public:
	Matrix();
	Matrix(unsigned int row, unsigned int column);
	Matrix(const Matrix& m);
	~Matrix();


	Matrix& operator= (const Matrix& m);

	friend Matrix operator+ (const Matrix& m1, const Matrix m2);
	friend ostream& operator<< (ostream& s, const Matrix& m);
};


#endif //MATRIX_MATRIX_H
