#include <iostream>
#include <cassert>
#include "matrix.h"

//Нужно написать класс - матрицу, тип элементов int.
//В конструкторе задается количество рядов и строк.
//Поддерживаются оперции : получить количество строк(rows) / столбцов(columns),
//получить конкретный элемент, умножить на число(*= ), сравнение на равенство / неравенство.
//В случае ошибки выхода за границы бросать исключение :


int main()
{
	const size_t rows = 5;
	const size_t cols = 3;

	Matrix m(rows, cols);

	assert(m.getRows() == 5);
	assert(m.getColumns() == 3);

	m[1][2] = 5; // строка 1, колонка 2
	double x = m[4][1];

	m *= 3; // умножение на число

	Matrix m1(rows, cols);

	if (m1 == m)
	{
		std::cout << "m1 == m";
	}
	return 0;
}