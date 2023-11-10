#include "pch.h"
#include "CppUnitTest.h"
#include "../PPOIS/MaterialMatrix.h"
#include "../PPOIS/MaterialMatrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace MatMatrixTest
{
	TEST_CLASS(MatMatrixTest)
	{
	public:
		
		TEST_METHOD(constructor)
		{
			MaterialMatrix matrix(3, 3);
			Assert::AreEqual(3, matrix.getRowsCount());
			Assert::AreEqual(3, matrix.getColumnsCount());
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(0.0, matrix.getElem(i, j));
				}
			}
		}
		TEST_METHOD(loadMatrixFromFile)
		{
			MaterialMatrix matrix(2, 2);
			matrix.loadMatrixFromFile("C:/Users/Deez nuts/Desktop/PPOIS/PPOIS/Matrix.txt");
			double example[2][2] = {
				{1, 2},
				{4, 1}
			};
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					Assert::AreEqual(example[i][j], matrix.getElem(i, j));
				}
			}
		}
		TEST_METHOD(increment, decrement)
		{
			MaterialMatrix matrix(3, 3);
			matrix++;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(1.0, matrix.getElem(i, j));
				}
			}
			++matrix;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(2.0, matrix.getElem(i, j));
				}
			}
			matrix--;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(1.0, matrix.getElem(i, j));
				}
			}
			--matrix;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					Assert::AreEqual(0.0, matrix.getElem(i, j));
				}
			}
		}
		TEST_METHOD(changeRows, changeColumns)
		{
			MaterialMatrix matrix(3, 3);
			matrix.changeRows(-1);
			Assert::AreEqual(2, matrix.getRowsCount());
			matrix.changeRows(1);
			Assert::AreEqual(3, matrix.getRowsCount());
			matrix.changeColumns(-1);
			Assert::AreEqual(2, matrix.getColumnsCount());
			matrix.changeColumns(1);
			Assert::AreEqual(3, matrix.getColumnsCount());
		}
		TEST_METHOD(subMatrix)
		{
			MaterialMatrix matrix(3, 3);
			matrix.subMatrix(2, 2);
			Assert::AreEqual(2, matrix.getColumnsCount());
			Assert::AreEqual(2, matrix.getRowsCount());
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					Assert::AreEqual(0.0, matrix.getElem(i, j));
				}
			}
		}
		TEST_METHOD(transposed)
		{
			MaterialMatrix matrix(2,2);
			matrix.loadMatrixFromFile("C:/Users/Deez nuts/Desktop/PPOIS/PPOIS/Matrix.txt");
			double example[2][2];
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					example[i][j] = matrix.getElem(j, i);
				}
			}
			matrix.transposeMatrix();
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					Assert::AreEqual(example[i][j], matrix.getElem(i, j));
				}
			}
		}
		TEST_METHOD(isSquare)
		{
			MaterialMatrix matrix(2, 2);
			Assert::AreEqual(true, matrix.isSquare());
		}
		TEST_METHOD(isZero)
		{
			MaterialMatrix matrix(2, 2);
			Assert::AreEqual(true, matrix.isZero());
		}
		TEST_METHOD(isUnit)
		{
			MaterialMatrix matrix(2, 2);
			matrix++;
			Assert::AreEqual(true, matrix.isUnit());
		}
		TEST_METHOD(isSymmetrical)
		{
			MaterialMatrix matrix(3, 3);
			matrix.loadMatrixFromFile("C:/Users/Deez nuts/Desktop/PPOIS/PPOIS/Symmetrical.txt");
			Assert::AreEqual(true, matrix.isSymmetric());
		}
		TEST_METHOD(isDiagonal)
		{
			MaterialMatrix matrix(3, 3);
			matrix.loadMatrixFromFile("C:/Users/Deez nuts/Desktop/PPOIS/PPOIS/Diagonal.txt");
			Assert::AreEqual(true, matrix.isDiagonal());
		}
		TEST_METHOD(isUpperTriangular)
		{
			MaterialMatrix matrix(3, 3);
			matrix.loadMatrixFromFile("C:/Users/Deez nuts/Desktop/PPOIS/PPOIS/UpperTriangular.txt");
			Assert::AreEqual(true, matrix.isUpperTriangular());
		}
		TEST_METHOD(isLowerTriangular)
		{
			MaterialMatrix matrix(3, 3);
			matrix.loadMatrixFromFile("C:/Users/Deez nuts/Desktop/PPOIS/PPOIS/LowerTriangular.txt");
			Assert::AreEqual(true, matrix.isLowerTriangular());
		}
	};
}