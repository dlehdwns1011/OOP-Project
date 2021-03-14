#include <iostream>

using namespace std;

//Bubble sorting with descending 
void Descending(int *arr, int a)
{
	int i, j, temp = 0;
	for (j = 0; j<a - 1; j++)
	{
		for (i = 0; i<a - 1; i++)
		{
			if (*(arr + i)<*(arr + i + 1))
			{
				temp = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = temp;
			}//end if
		}//end for
	}//end for
}

int main()
{
	int age;
	cout << "<Input>" << endl;
	cout << "Messi's age : ";
	cin >> age; //input age
	if (1 > age || 10000 < age)
	{
		cout << "Error : not age" << endl;
		return 0;
	}
	int can[100000]; //declare
	cout << "Heights of candles : ";
	for (int i = 0; i != age; i++)
	{//input candle heights
		cin >> can[i];
		if (1 > can[i] || 1000 < can[i])
		{//candle error
			cout << "Error : candle heights" << endl;
			return 0;
		}
	}
	cout << "<Output>" << endl;
	Descending(can, age);//go to function of Bubble sorting with descending
	int i; int count = 0;
	for (i = 0; i != age; i++)
	{//counting number of tallest candles
		if (can[i] == can[i + 1])
			count++;
		else
		{
			count++;
			break;
		}
	}
	//output
	cout << "The number of candles that Messi blows out is " << count;

	return 0;
}