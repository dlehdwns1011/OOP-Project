#include "Encode.h"
#include <iostream>

using namespace std;

Encode::Encode(void)
{
}

Encode::~Encode(void)
{
}

void Encode::inputWord()
{//input word
	cout << "Input word : ";
	cin >> word;
	for (int i = 0; word[i] != '\0'; i++)
	{//if input not alphabets
		if (97 > (int)word[i] || (int)word[i] > 122)
		{
			cout << "Error : input had not alphabet";
			exit(100);
		}
	}
}

char* Encode::getBuf(void)
{//get buffer(wordencoded) function
	return buffer;
}

void Encode::printEncResult()
{//print output result of Encoding 
	cout << "Encoding result" << endl;
	cout << buffer << endl;
}

int Encode::encodeWord(void)
{//encoding
	int count = 0; //declare
	for (int i = 0; word[i] != NULL; i++)
	{
		int c = word[i];
		for (int j = c - 97; j != 0; j--)
		{//store in buffer 0 according to ASCII
			buffer[count++] = '0';
		}
		if ((int)word[i] < 122) //if alphabet is not z
			buffer[count++] = '1';//store 1
	}
	buffer[count] = '\0';//make end string
	return 0;
}