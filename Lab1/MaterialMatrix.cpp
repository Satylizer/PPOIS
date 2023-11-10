#include "MaterialMatrix.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

MaterialMatrix::MaterialMatrix(int resRows, int resColumns) {
	this->rows = resRows;
	this->columns = resColumns;
	matMatrix = new double* [rows];
	for (size_t i = 0; i < rows; i++) {
		matMatrix[i] = new double[columns];
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matMatrix[i][j] = 0;
		}
	}
}

MaterialMatrix::MaterialMatrix(const MaterialMatrix& other) {
	this->columns = other.columns;
	this->rows = other.rows;
	this->matMatrix = new double* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		matMatrix[i] = new double[columns];
		for (size_t j = 0; j < columns; j++)
		{
			this->matMatrix[i][j] = other.matMatrix[i][j];
		}
	}
}

MaterialMatrix::~MaterialMatrix() {
	for (size_t i = 0; i < rows; i++)
	{
		delete[] matMatrix[i];
	}
	delete[] matMatrix;
}

MaterialMatrix& MaterialMatrix::operator--() {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			matMatrix[i][j] -= 1;
		}
	}
	return *this;
}

MaterialMatrix& MaterialMatrix::operator--(int) {
	MaterialMatrix copy(*this);
	operator--();
	return copy;
}

MaterialMatrix& MaterialMatrix::operator++() {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < columns; j++) {
			matMatrix[i][j] += 1;
		}
	}
	return *this;
}

MaterialMatrix& MaterialMatrix::operator++(int) {
	MaterialMatrix copy(*this);
	operator++();
	return copy;
}

void MaterialMatrix::inputMatrix() {
	cout << "Введите элементы матрицы:" << endl;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			double elem;
			cin >> elem;
			matMatrix[i][j] = elem;
		}
	}
}

void MaterialMatrix::loadMatrixFromFile(const char* filename) {
	ifstream file;
	file.open(filename);

	if (!file.is_open()) {
		return;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (file.fail()) {
				file.close();
				return;
			}
			file >> matMatrix[i][j];
		}
	}

	file.close();
}

void MaterialMatrix::printMatrix() {
	cout << '\n' << "------ Matrix ------" << endl;
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			cout << " " << matMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int MaterialMatrix::getRowsCount() {
	return this->rows;
}

int MaterialMatrix::getColumnsCount() {
	return this->columns;
}

double MaterialMatrix::getElem(int i, int j) {
	if (i >= 0 && i < rows && j >= 0 && j < columns) {
		return matMatrix[i][j];
	}
	else
	{
		return 0;
	}
}

void MaterialMatrix::setElem(double elem, int i, int j)
{
	if (i >= 0 && i < rows && j >= 0 && j < columns) {
		matMatrix[i][j] = elem;	
	}
	else
	{
		return;
	}
}

void MaterialMatrix::changeRows(int dif) {
	if (dif < 0 && abs(dif) > rows || dif == 0) {
		return;
	}

	int newRows = rows + dif;

	double** newMatrix = new double* [newRows];
	for (int i = 0; i < newRows; i++) {
		newMatrix[i] = new double[columns];
	}

	for (int i = 0; i < newRows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i < rows) {
				newMatrix[i][j] = matMatrix[i][j];
			}
		}
	}

	if (dif > 0) {

		for (int i = rows; i < newRows; i++) {
			for (int j = 0; j < columns; j++) {
				newMatrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		delete[] matMatrix[i];
	}
	delete[] matMatrix;

	matMatrix = newMatrix;
	rows = newRows;
}

void MaterialMatrix::changeColumns(int dif) {

	if (dif < 0 && abs(dif) > columns || dif == 0) {
		return;
	}

	int newColumns = columns + dif;

	double** newMatrix = new double* [rows];
	for (int i = 0; i < rows; i++) {
		newMatrix[i] = new double[newColumns];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < newColumns; j++) {
			if (j < columns) {
				newMatrix[i][j] = matMatrix[i][j];
			}
		}
	}

	if (dif > 0) {
		for (int i = 0; i < rows; i++) {
			for (int j = columns; j < newColumns; j++) {
				newMatrix[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		delete[] matMatrix[i];
	}
	delete[] matMatrix;

	matMatrix = newMatrix;
	columns = newColumns;
}

void MaterialMatrix::subMatrix(int subRows, int subColumns) {

	if (subColumns > columns || subRows > rows) {
		return;
	}

	double** subMatrix = new double* [subRows];
	for (int i = 0; i < subRows; i++) {
		subMatrix[i] = new double[subColumns];
	}

	cout << '\n' << "------ subMatrix ------" << endl;
	for (int i = 0; i < subRows; i++) {
		for (int j = 0; j < subColumns; j++) {
			subMatrix[i][j] = matMatrix[i][j];
			cout << " " << subMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < rows; i++) {
		delete[] matMatrix[i];
	}
	delete[] matMatrix;

	matMatrix = subMatrix;
	columns = subColumns;
	rows = subRows;
}

void MaterialMatrix::transposeMatrix() {
	if (!isSquare()) {
		return;
	}

	double** transposedMatrix = new double* [columns];
	for (int i = 0; i < columns; i++) {
		transposedMatrix[i] = new double[rows];
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			transposedMatrix[j][i] = matMatrix[i][j];
		}
	}

	cout << '\n' << "------ transposeMatrix ------" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << " " << transposedMatrix[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < rows; i++) {
		delete[] matMatrix[i];
	}
	delete[] matMatrix;

	matMatrix = transposedMatrix;
}

bool MaterialMatrix::isSquare() {
	return rows == columns;
}

bool MaterialMatrix::isUnit() {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (matMatrix[i][j] != 1) {
				return false;
			}
		}
	}
	return true;
}

bool MaterialMatrix::isZero() {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (matMatrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

bool MaterialMatrix::isSymmetric() {
	if (!isSquare()) {
		return false;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (matMatrix[i][j] != matMatrix[j][i]) {
				return false;
			}
		}
	}
	return true;
}

bool MaterialMatrix::isDiagonal() {
	if (!isSquare()) {
		return false;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			if (i != j && matMatrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

bool MaterialMatrix::isUpperTriangular() {
	if (!isSquare()) {
		return false;
	}
	if (isZero()) {
		return false;
	}
	if (isDiagonal()) {
		return false;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < i; j++) {
			if (matMatrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

bool MaterialMatrix::isLowerTriangular() {
	if (!isSquare()) {
		return false;
	}
	if (isZero()) {
		return false;
	}
	if (isDiagonal()) {
		return false;
	}

	for (int i = 0; i < rows; i++) {
		for (int j = i + 1; j < columns; j++) {
			if (matMatrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

void MaterialMatrix::matrixType() {
	if (isSquare() == true) {
		cout << "Матрица квадратная" << endl;
	}
	if (isUnit() == true) {
		cout << "Матрица единичная" << endl;
	}
	if (isZero() == true) {
		cout << "Матрица нулевая" << endl;
	}
	if (isSymmetric() == true) {
		cout << "Матрица симметричная" << endl;
	}
	if (isDiagonal() == true) {
		cout << "Матрица диоганальная" << endl;
	}
	if (isUpperTriangular() == true) {
		cout << "Матрица верхняя треугольная" << endl;
	}
	if (isLowerTriangular() == true) {
		cout << "Матрица нижняя треугольная" << endl;
	}
}