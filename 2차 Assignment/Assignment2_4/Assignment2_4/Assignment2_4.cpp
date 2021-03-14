#include <iostream>
#include "Encode.h"
#include "Decode.h"

using namespace std;

int main()
{//start main
	Encode encode; //declare object Encode class
	encode.inputWord(); //input word
	encode.encodeWord(); //encoding
	encode.printEncResult(); //print output
	cout << endl;
	Decode decode; //declare object Encode class
	decode.SetBuf(encode.getBuf()); //send data
	decode.decodebin(); //decoding
	decode.printWord(); //print output

	return 0;//end main
}