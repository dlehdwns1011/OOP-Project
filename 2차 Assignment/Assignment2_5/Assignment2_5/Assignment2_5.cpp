#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{//start main
	Matrix mat1,mat2,mat3,mat4,mat5; //declare Matrix
	
	mat1.set_matrix();
	mat2.set_matrix();//input Matrix

	cout << "+ operation" << endl;
	mat3 = mat1 + mat2; //addition of Matrix(result is mat3)
	mat3.print_matrix(); //print output result
	cout << "- operation" << endl;
	mat3 = mat1 - mat2; //subtraction of Matrix(result is mat3)
	mat3.print_matrix(); //print output result
	cout << "* operation" << endl;
	mat3 = mat1 * mat2; //multiplication of Matrix(result is mat3)
	mat3.print_matrix(); //print output result

	cout << "L rotation" << endl;
	mat4 = mat1.rotation_Left(); //Left rotation of mat1(result is mat4)
	mat4.print_matrix(); //print output result
	cout << "R rotation" << endl;
	mat4 = mat4.rotation_Right(); //Left rotation of mat4(result is mat4)
	mat4.print_matrix(); //print output result
	cout << "Inverse" << endl;
	mat5 = mat4.inverse(); //Find inverse Matrix of mat4(result is mat5)
	mat5.print_matrix(); //print output result


	return 0;//end main
}