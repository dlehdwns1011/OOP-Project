#include "Matrix.h"
#include <iostream>
Matrix::Matrix()
{
}
Matrix::~Matrix()
{
}
Matrix Matrix::operator= (const Matrix &m)
{//operator = -> move data
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
			matrix[row][col] = m.matrix[row][col];
	}
	return *this; //return result
}
Matrix Matrix::operator+ (const Matrix &m)
{//addition of Matrix
	Matrix result; //declare Matrix have result
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{//make result Matrix using addition
			result.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
		}
	}
	return result; //return result
}
Matrix Matrix::operator- (const Matrix &m)
{//subtraction of Matrix
	Matrix result; //declare Matrix have result
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{//make result Matrix using subtraction
			result.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
		}
	}
	return result; //return result
}
Matrix Matrix::operator* (const Matrix &m)
{//multiplication of Matrix
	Matrix result; //declare Matrix have result

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{//make result Matrix using multiplication
			result.matrix[i][j] = matrix[i][0] * 
				m.matrix[0][j] + matrix[i][1] * 
				m.matrix[1][j] + matrix[i][2] * 
				m.matrix[2][j]; 
		//By using law of Multiplication of 3x3 Matrix, make result Matrix
		}
	}

	return result; //return result
}
Matrix Matrix::rotation_Left()
{//Left rotation of Matrix
	Matrix result; //declare Matrix have result
	for (int i = 0; i < 3; i++)
		result.matrix[0][i] = matrix[i][2]; //first row of result Matrix
	for (int i = 0; i < 3; i++)
		result.matrix[1][i] = matrix[i][1]; //second row of result Matrix
	for (int i = 0; i < 3; i++)
		result.matrix[2][i] = matrix[i][0]; //third row of result Matrix
	return result; //return result
}
Matrix Matrix::rotation_Right()
{
	Matrix result; //declare Matrix have result
	for (int i = 0; i < 3; i++)
		result.matrix[i][0] = matrix[2][i]; //first column of result Matrix
	for (int i = 0; i < 3; i++)
		result.matrix[i][1] = matrix[1][i]; //second column of result Matrix
	for (int i = 0; i < 3; i++)
		result.matrix[i][2] = matrix[0][i]; //third column of result Matrix
	return result; //return result
}
Matrix Matrix::inverse()
{
	Matrix result; //declare Matrix have result
	double a = matrix[0][0]; double b = matrix[0][1]; double c = matrix[0][2];
	double d = matrix[1][0]; double e = matrix[1][1]; double f = matrix[1][2];
	double g = matrix[2][0]; double h = matrix[2][1]; double i = matrix[2][2];
	double D = a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
	if (D == 0)
	{
		result.matrix[0][0] = NULL;
		return result;
	}
	//(a b c)
	//(d e f)
	//(g h i) -> store each value 

	result.matrix[0][0] = (e*i - f*h) / D;
	result.matrix[0][1] = -(b*i - c*h) / D;
	result.matrix[0][2] = (b*f - c*e) / D;
	result.matrix[1][0] = -(d*i - f*g) / D;
	result.matrix[1][1] = (a*i - c*g) / D;
	result.matrix[1][2] = -(a*f - c*d) / D;
	result.matrix[2][0] = (d*h - e*g) / D;
	result.matrix[2][1] = -(a*h - b*g) / D;
	result.matrix[2][2] = (a*e - b*d) / D; 
	//make inverse Matrix in result by using law of 3x3 inverse Matrix
	return result; //return result
}