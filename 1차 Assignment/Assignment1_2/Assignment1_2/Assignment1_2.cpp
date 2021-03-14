#include <iostream>

using namespace std;

int main()
{//start main
	char mark; //declare type of char
	int n; //declare
	while (1)
	{
		cout << "Input your mark : ";
		cin >> mark; //input mark of star
		cout << "Input N : ";
		cin >> n; //input length of one side of star
		if (n % 2 == 0)
		{//if 'input N' is even num
			cout << "Error : please enter odd number!" << endl;
		}
		else
			break;
	}
	cout << "Output : " << endl;
	int count = 0; //using to know line
	for (int i = n * 3 - 1; count < n; i--)
	{//output of first triangle of star
		count++;
		for (int j = i; j != 0; j--)
			cout << " ";//make space
		for (int j = count; j != 0; j--)
			cout << mark << " "; //output mark
		cout << endl;
	}
	count = 3 * n;
	for (int i = 0; i != n; i++)
	{//output of middle trapezoid of star
		for (int j = i; j != 0; j--)
			cout << " ";//make space
		for (int j = count; j != 0; j--)
			cout << mark << " ";//output mark
		cout << endl;
		count--;
	}
	count = 0;
	int s = 3;
	for (int i = 0; i != n; i++)
	{//output of last 2 triangle of star
		for (int j = n - 1; j != 0; j--)
			cout << " "; //make space
		for (int j = n - count; j != 0; j--)
			cout << mark << " "; //output mark of first triangle of last
		for (int h = 1; h != s; h++)
			cout << " ";//make space between 2 triangle
		for (int j = n - count; j != 0; j--)
			cout << mark << " ";//output mark of second triangle of last
		s = s + 4;
		cout << endl;
		count++;
	}

	return 0;

}//end main