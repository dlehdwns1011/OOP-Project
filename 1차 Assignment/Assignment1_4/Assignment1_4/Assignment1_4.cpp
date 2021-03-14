#include <iostream>

using namespace std;

bool InsertString(char* str1, char* str2, int n)
{//function of insert str2 to str1
	int i;
	for (i = 0; str1[i] != NULL; i++); //find length of str1

	if (n > i)
	{//if n is longer than length of str1, end function
		cout << "Error : n > sizeof str1";
		return 0; //fail
	}
	int j;
	for (j = 0; str2[j] != NULL; j++); //find length of str2
	char str3[1024]; //declare for insert str2 to str1

	int x;
	int y;
	for (x = 0; x != n; x++)
		str3[x] = str1[x]; //insert str1 to str3 from str1[0] to str1[n-1]
	int a = x;
	for (y = 0; y != j; y++)
	{//insert str2 to str3 
		str3[x] = str2[y];
		x++;
	}
	for (; a < i; a++)
	{//insert str1 to str3 from str1[n] to end
		str3[x] = str1[a];
		x++;
	}

	str3[x] = '\0';
	int c;
	for (c = 0; str3[c] != '\0'; c++)
		str1[c] = str3[c]; //copy - make new str1
	str1[c] = '\0';

	return 1; //success
}

int main()
{
	char str1[512];
	char str2[512]; //declare for input string
	int n = 0;

	cout << "str1 : ";
	cin.getline(str1, 512); //input str1
	cout << "str2 : ";
	cin.getline(str2, 512); //input str2

	cout << "n : ";
	cin >> n; //input n
	bool result = InsertString(str1, str2, n);
	if (result == 0) //go to function
					 //if n is longer than length of str1 (fail)
	{
		cout << endl << result << "(fail)";
		return 0; //end main
	}
	//(success)
	cout << "str1 : " << str1;
	cout << endl << result << "(success)";

	return 0; //end main

}