#pragma once

class MaterialMatrix
{
private:
	double** matMatrix;
	int rows;
	int columns;
public:
	MaterialMatrix(int resRows, int resColumns);

	MaterialMatrix(const MaterialMatrix& other);

	~MaterialMatrix();

	MaterialMatrix& operator--();

	MaterialMatrix& operator--(int);

	MaterialMatrix& operator++();

	MaterialMatrix& operator++(int);

	void inputMatrix();

	void loadMatrixFromFile(const char* filename);

	void printMatrix();

	int getRowsCount();

	int getColumnsCount();

	double getElem(int i, int j);

	void setElem(double elem, int i, int j);

	void changeRows(int dif);

	void changeColumns(int dif);

	void subMatrix(int subRows, int subColumns);

	void transposeMatrix();

	void matrixType();

	bool isSquare();

	bool isUnit();

	bool isZero();

	bool isSymmetric();

	bool isDiagonal();

	bool isUpperTriangular();

	bool isLowerTriangular();
};