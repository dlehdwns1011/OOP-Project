#pragma once
#include <iostream>
using namespace std;
class Matrix
{
private:
	double matrix[3][3]; //declare value is Matrix

public:
	Matrix();
	~Matrix();

	void set_matrix()
	{//input Matrix
		cout << "Input 3x3 matrix" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> matrix[i][j]; //input value in 3x3 Matrix
			}
		}
	}
	void print_matrix()
	{//print Matrix
		if (matrix[0][0] == NULL)
		{
			cout << "Not exist Matrix!!" << endl;
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cout << matrix[i][j] << " ";
			}//print Matrix 
			cout << endl;
		}
		cout << endl;
	}
	Matrix operator= (const Matrix &m);
	Matrix operator+ (const Matrix &m);
	Matrix operator- (const Matrix &m);
	Matrix operator* (const Matrix &m);
	Matrix rotation_Left ();
	Matrix rotation_Right();
	Matrix inverse(); //declare function
};