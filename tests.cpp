#include <iostream>
#include "matrix.h"
#include <algorithm>

int resetTest(const std::string& message,
				int** data1, int** data2, 
				const size_t size, 
				const int result)
{
	std::cout << message << std::endl;
	for (size_t i = 0; i < size; ++i)
	{
		delete[] data1[i];
		delete[] data2[i];
	}
	return result;
}

int main()
{
	int testNum = 10;
	for (; testNum >= 0; --testNum)
	{
		std::cout << "start test" << std::endl;
		const size_t rows = rand() % 10 + 1;
		const size_t cols = rand() % 10 + 1;
		
		Matrix m(rows, cols);
		Matrix mEqualTest(rows, cols);
		int** mTest = new int*[rows];
		int** mTestMult = new int*[rows];

		int coeff = rand() % 10;

		for (size_t i = 0; i < rows; ++i)
		{
			mTest[i] = new int[cols];
			mTestMult[i] = new int[cols];
			for (size_t j = 0; j < cols; ++j)
			{
				mTest[i][j] = rand() % 100;
				mTestMult[i][j] = mTest[i][j] * coeff;
				m[i][j] = mTest[i][j];
				mEqualTest[i][j] = mTest[i][j];
			}
		}
		
		for (size_t i = 0; i < rows; ++i)
		{
			for (size_t j = 0; j < cols; ++j)
			{
				if (m[i][j] != mTest[i][j])
					return resetTest("bad matrix test",
									mTest, mTestMult, rows, 1);
				if (coeff * m[i][j] != mTestMult[i][j])
					return resetTest("bad =* operator test",
									mTest, mTestMult, rows, 1);
			}
		}

		std::cout << "good matrix test" << std::endl;
		std::cout << "good =* operator test" << std::endl;
		
		if (m != mEqualTest)
			return resetTest("bad == and =! operators test",
							mTest, mTestMult, rows, 1);
		
		resetTest("good == operator test", mTest, mTestMult, rows, 0);
	}
	return 0;
}