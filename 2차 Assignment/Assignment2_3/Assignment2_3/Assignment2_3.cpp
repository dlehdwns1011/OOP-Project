#include <iostream>
#include <cstring>

using namespace std;

void biggerIsGreater(char* input, char* output);
void Ascending(int *arr, int n, int a); //declare function

int main()
{//start main
	char str[10]; //declare for input string
	char result[10] = "\0";//declare for output string

	cout << "Input the string : ";
	cin.getline(str, 10); //input string
	biggerIsGreater(str, result); //function of Lexicographical order
	cout << "Output : ";
	cout << result;
	return 0;
	//end main
}

void biggerIsGreater(char* input, char* output)
{//function of Lexicographical order
	int result[10]; int n; int c;  int j; int a; //declare values
	for (n = 0; input[n] != '\0'; n++); n--; //check lenght of string
	for (j = 0; input[j] != '\0'; j++)
		result[j] = (int)input[j]; //change int
	result[j] = '\0';
	for (int i = n; i >= 1; i--)
	{
		if (result[i - 1] < result[i])
		{//if find position changed
			c = result[n];
			for (a = n; a >= i; a--)
			{//find alphabet replace in position changed
				if (result[i - 1] < result[a])
					break; //if find alphabet
			}
			int temp = result[a];
			result[a] = result[i - 1]; 
			result[i - 1] = temp;//changing
			Ascending(result, j-1,i); //function of sorting
			break;
		}
	}
	int flag = 0; //answer flag
	for (int i = 0; result[i] != '\0'; i++)
	{//check result
		if (input[i] != (char)result[i])
			flag++;
	}
	if (flag != 0) //if success
		for (int i = 0; i < n + 1; i++)
			output[i] = (char)result[i]; //change char
	else//if fail
		strcpy(output, "no answer");
}

void Ascending(int *arr, int size ,int p)
{//sorting from input array[p] to end of array
	//Ascending sorting
	int temp = 0; 
	for (int i = p; i < size; i++)
	{
		for (int j = p; j < size; j++)
		{
			if (arr[j] > arr[j + 1])
			{//if need to change
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}