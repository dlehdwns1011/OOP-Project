#pragma once
class Decode
{
private:
	char word[255];
	char buffer[255]; //decalre value

public:
	Decode(void);
	~Decode(void);

	//declare function
	void SetBuf(char* buf); //set Buffer function
	void printWord(); //print word function

	int decodebin(void); //decoding fucntion
};

