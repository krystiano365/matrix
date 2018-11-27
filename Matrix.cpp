//
// Created by krystian on 25.11.18.
//

#include <iostream>
#include "Matrix.h"


// ===============================================================================================================================================
// =====================================================================================================================PRIVATE METHODS


void Matrix::allocate() {
	array = new double*[rows_no];		// creating array of arrays
	for(unsigned int r = 0 ; r < rows_no ; r++) {
		array[r] = new double[columns_no];
	}
}

// ===============================================================================================================================================
// =====================================================================================================================CONSTRUCTORS


Matrix::Matrix() {
	rows_no = 0;
	columns_no = 0;

	array = nullptr;
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

Matrix::Matrix(unsigned int rows, unsigned int columns, double initVal) {
	rows_no = rows;
	columns_no = columns;

	allocate();

	for(unsigned int r = 0 ; r < rows ; r++) {
		for(unsigned int c = 0 ; c < columns ; c++) {
			array[r][c] = initVal;
		}
	}
}

Matrix::Matrix(const Matrix &m) {
	this->rows_no = m.rows_no;
	this->columns_no = m.columns_no;
	this->array = m.array;

//	allocate();
//	for(unsigned int r = 0 ; r < this->rows_no ; r++) {
//		for(unsigned int c = 0 ; c < this->columns_no ; c++) {
//			this->array[r][c] = m.array[r][c];
//		}
//	}
}

Matrix::~Matrix() {																										//destructor
	for(unsigned int r = 0; r < rows_no; r++) {
		delete[] array[r];
	}
	//delete[] array;
}


// ===============================================================================================================================================
// =====================================================================================================================PUBLIC METHODS


int Matrix::getReferences() {
	return this->array.getReferences();
}

Matrix &Matrix::perfectCopy(const Matrix &m) {
	Matrix temp(m);

	temp.rows_no = m.rows_no;
	temp.columns_no = m.columns_no;

	temp.allocate();

	for(unsigned int r = 0 ; r < temp.rows_no ; r++) {
		for(unsigned int c = 0 ; c < temp.columns_no ; c++) {
			temp.array[r][c] = m.array[r][c];
		}
	}

	return *this = temp;
}

Matrix &Matrix::operator=(const Matrix &m) {
	this->rows_no = m.rows_no;
	this->columns_no = m.columns_no;
	this->array = m.array;
	return *this;
}

Matrix &Matrix::operator+=(const Matrix &m) {
	if (this->rows_no == m.rows_no && this->columns_no == m.columns_no) {
		perfectCopy(*this);
		for (unsigned int r = 0; r < this->rows_no; r++) {
			for (unsigned int c = 0; c < this->columns_no; c++) {
				this->array[r][c] += m.array[r][c];
			}
		}
	} else {
		throw AdditionDifferentSizesException();
	}
	return *this;
}

Matrix &Matrix::operator*=(const Matrix &m) {
	if (this->columns_no == m.rows_no) {
		Matrix result(this->rows_no, m.columns_no);
		for (unsigned int k = 0; k < this->rows_no; k++) {
			for (unsigned int j = 0; j < m.columns_no; j++) {
				for(unsigned int i = 0; i < this->columns_no; i++) {
					result.array[k][j] = array[k][i] * m.array[i][j];
				}
			}
		}
		*this = result;  // todo: zrobić = copy operator
	} else {
		throw MultiplicationDifferentSizesException();
	}

	return *this;
}


// ===============================================================================================================================================
// =====================================================================================================================FRIEND METHODS


Matrix operator+(const Matrix &m1, const Matrix &m2) {

	Matrix result(m1);

	result += m2;

	return result;
}

ostream &operator<<(ostream &s, const Matrix &m) {
	if (&(m.array) && m.rows_no > 0 && m.columns_no > 0) {
		for (unsigned int r = 0; r < m.rows_no; r++) {
			s << "[";
			for (unsigned int c = 0; c < m.columns_no; c++) {
				s << " " << m.array[r][c];
			}
			s << " ] r:" << r + 1 << endl;
		}
		s << "c:";
		for (unsigned int c = 1; c <= m.columns_no; c++) s << c % 10 << " ";
		s << endl;
		return s;
	} else {
		s << "[none]"  << endl;
		return s;
	}
}




