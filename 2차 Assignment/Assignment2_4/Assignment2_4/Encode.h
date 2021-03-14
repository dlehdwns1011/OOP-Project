#pragma once
class Encode
{
private:
	char word[255];
	char buffer[255]; //declare value

public:
	Encode();
	~Encode();

	//declare function
	void inputWord(); //input function
	char* getBuf(void); //get buffer function
	void printEncResult(); //print result function

	int encodeWord(void);  //encoding function
};

