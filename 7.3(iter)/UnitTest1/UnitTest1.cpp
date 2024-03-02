#include "pch.h"
#include "CppUnitTest.h"
#include "../7.3(iter)/Source.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCountCols)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** matrix = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i) {
				matrix[i] = new int[colCount];
			}

			matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 2;
			matrix[1][0] = 0; matrix[1][1] = 3; matrix[1][2] = 0;
			matrix[2][0] = 4; matrix[2][1] = 0; matrix[2][2] = 5;

			int count = 0;
			bool result = false;
			CountCols(matrix, rowCount, colCount, count, result, 0);

			Assert::AreEqual(5, count);
			Assert::IsTrue(result);

			for (int i = 0; i < rowCount; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}

		TEST_METHOD(TestLongestSeries)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** matrix = new int* [rowCount];
			for (int i = 0; i < rowCount; ++i) {
				matrix[i] = new int[colCount];
			}

			matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 2;
			matrix[1][0] = 0; matrix[1][1] = 3; matrix[1][2] = 0;
			matrix[2][0] = 4; matrix[2][1] = 0; matrix[2][2] = 5;

			try {
				LongestSeries(matrix, rowCount, colCount);
			}
			catch (...) {
				Assert::Fail(L"Exception thrown");
			}

			for (int i = 0; i < rowCount; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}