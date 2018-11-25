//
// Created by krystian on 25.11.18.
//

#include "Matrix.h"

void Matrix::allocate() {
	array = new double*[rows_no];
	for(unsigned int r = 0 ; r < rows_no ; r++) {
		array[r] = new double[columns_no];
	}
}

Matrix::Matrix() {
	rows_no = 1;
	columns_no = 1;

	allocate();

	array[0][0] = 0;
}

Matrix::Matrix(unsigned int rows, unsigned int columns) {
	rows_no = rows;
	columns_no = columns;

	allocate();

	for(unsigned int r = 0 ; r < rows ; r++) {
		for(unsigned int c = 0 ; c < columns ; c++) {
			array[r][c] = 0;
		}
	}
}

Matrix::Matrix(const Matrix &m) {
	this->rows_no = m.rows_no;
	this->columns_no = m.columns_no;

	allocate();

	for(unsigned int r = 0 ; r < this->rows_no ; r++) {
		for(unsigned int c = 0 ; c < this->columns_no ; c++) {
			this->array[r][c] = m.array[r][c];
		}
	}
}

Matrix::~Matrix() {
	for(unsigned int r = 0; r < rows_no; r++) {
		delete[] array*;
	}
	delete[] array;
}

Matrix &Matrix::operator=(const Matrix &m) {
}


