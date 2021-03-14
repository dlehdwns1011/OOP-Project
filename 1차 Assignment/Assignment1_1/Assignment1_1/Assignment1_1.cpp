#include <iostream>

using namespace std;

int main()
{//start main
	int input; int count = 0;
	int max = 0; int min;
	int sum = 0; int avr = 0; //declare type of int

	while (1)
	{
		cout << "Input : "; //output
		cin >> input; //input start value
		if (input < 0)
			cout << "Error : please enter unsigned number!" << endl;
		else
			break;
	}
	int x = input; //declare
	min = input;

	cout << endl << "Collatz conjecture : ";

	while (1) //start while
	{
		cout << x << " ";
		sum = sum + x; //calculate sum of numbers
		if (max < x)//if need to change max num
			max = x; //change
		else if (min > x)//if need to change min num
			min = x;//change

		if (x == 1)//if don't have to more calculattion
			break;//break while

		if (x % 2 == 0)
			x = x / 2; //if even num
		else
			x = 3 * x + 1;//if odd num
		cout << "-> ";
		count++;//count = count + 1
	}//end while
	avr = sum / (count + 1); //calculate average
	cout << endl << endl;
	cout << "Count : " << count << endl << endl;
	cout << "Max : " << max << endl << endl;
	cout << "Min : " << min << endl << endl;
	cout << "Sum : " << sum << endl << endl;
	cout << "Average : " << avr << endl; //output of result

	return 0;

}//end main