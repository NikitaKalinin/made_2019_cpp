#include "matrix.h"
#include <cstring>

Matrix::Matrix(const size_t rows, const size_t cols) :
	cols(cols), rows(rows)
{
	if ((cols == 0) ||
		(rows == 0)) throw std::logic_error("bad size of matrix");
	rowsArray = new Row[rows];
	for (size_t i = 0; i < rows; ++i)
	{
		int* temp = new int[cols];
		std::memset(temp, 0, cols * sizeof(int));
		rowsArray[i].values = temp;
		rowsArray[i].size = cols;
	}
}

const int& Matrix::Row::operator[](const size_t i) const
{
	if (i >= size)
		throw std::out_of_range("i >= number of cols");
	return values[i];
}

int& Matrix::Row::operator[](const size_t i)
{
	if (i >= size)
		throw std::out_of_range("i >= number of cols");
	return values[i];
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < rows; ++i)
		delete rowsArray[i].values;
}

const Matrix::Row& Matrix::operator[](const size_t i) const
{
	if (i >= rows)
		throw std::out_of_range("i >= number of rows");
	return rowsArray[i];
}

Matrix::Row& Matrix::operator[](const size_t i)
{
	if (i >= rows)
		throw std::out_of_range("i >= number of rows");
	return rowsArray[i];
}

Matrix& Matrix::operator*=(const int val)
{
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
			(*this)[i][j] *= val;
	}
	return *this;
}

bool Matrix::operator==(const Matrix& other) const
{
	if (this == &other)
		return true;
	if ((this->cols != other.cols) ||
		(this->rows != other.rows)) return false;
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			if ((*this)[i][j] != other[i][j])
				return false;
		}
	}

	return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
	return !(*this == other);
}

