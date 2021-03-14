#include <iostream>

using namespace std;
//Find perfect number in range
int main()
{
	int range; //declare
	while (1)
	{
		cout << "Max range value n : ";
		cin >> range; //input Max range value
		cout << endl;
		if (range <= 0)
			cout << "Error : please enter unsigned number" << endl;
		else
			break;
	}
	int sum = 0;
	int arr[10000]; //declare
	int count = 0; int count2 = 0;

	for (int i = 2; i <= range; i++)
	{//analyze each num 'i'
		for (int j = i; j > 1; j--)
		{//find divisor
			if (i%j == 0)
			{
				sum = sum + i / j; //calculation of divisors
				arr[count] = i / j;//insert divisors in array
				count++;
			}
		}
		if (sum == i)
		{//if num(i) is perfect num 
			cout << i << " = ";
			for (int j = 0; j != count - 1; j++)
			{//output divisors of perfect num
				cout << arr[j] << " + ";
			}
			cout << arr[count - 1] << endl;
			count2++;
		}
		count = 0;
		sum = 0; //reset count and sum
	}
	if (count2 == 0) //if cant find perfect number
		cout << "No one perfect number";

	return 0;
}
