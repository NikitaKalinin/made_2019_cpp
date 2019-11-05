#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix
{
private:
	size_t cols = 0;
	size_t rows = 0;
	class Row
	{
	public:
		size_t size = 0;
		int* values = nullptr;
		Row() {}
		Row(const Row&) = delete;
		Row(const Row&&) = delete;
		Row& operator=(const Row&) = delete;
		Row&& operator=(const Row&& other) = delete;

		const int& operator[](const size_t i) const;
		int& operator[](const size_t i);

	};
	Row* rowsArray = nullptr;
public:
	Matrix(const size_t rows, const size_t cols);
	~Matrix();
	Matrix(const Matrix&) = delete;
	Matrix(const Matrix&&) = delete;
	Matrix& operator=(const Matrix&) = delete;
	Matrix&& operator=(const Matrix&&) = delete;

	const Row& operator[](const size_t i) const;
	Row& operator[](const size_t i);

	Matrix& operator*=(const int val);

	bool operator==(const Matrix& other) const;
	bool operator!=(const Matrix& other) const;

	const size_t getRows() { return rows; }
	const size_t getColumns() { return cols; }
};

#endif // !MATRIX_H