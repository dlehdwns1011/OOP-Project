#include "Decode.h"
#include <iostream>

using namespace std;

Decode::Decode(void)
{
}


Decode::~Decode(void)
{
}

void Decode::SetBuf(char* buf)
{//set Buffer by using encoded buf
	int i;
	for (i = 0; buf[i] != NULL; i++)
		buffer[i] = buf[i];
	buffer[i] = NULL;
}

void Decode::printWord()
{//print output result of Decoding 
	cout << "Decoding result" << endl;
	cout << word << endl;;
}

int Decode::decodebin(void)
{//Decoding
	int i = 0; int c = 0;
	while (1)
	{
		int count = 0;
		for (; buffer[i] != '1'; i++)
		{//chack 0 for find alphabet
			count++;
			if (count == 25)
				break; //it is z case
		}
		word[c] = (char)(97 + count); //using ASCII, make alphabet
		c++; i++;
		if (buffer[i] != '1' && buffer[i] != '0')
			break; //end
	}
	word[c] = '\0'; //make string end \0
	return 0;
}