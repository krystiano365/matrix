//
// Created by krystian on 25.11.18.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H


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
};


#endif //MATRIX_MATRIX_H
