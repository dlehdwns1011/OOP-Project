#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class wordNode
{
private:
	char word[100]; //word in word node
	wordNode *wNext; //pointer of next word node
public:
	wordNode();
	~wordNode();
	//set word in word node
	void setword(char* nword) { strcpy_s(word,nword); }
	char* getword() { return word; } //get word in word node
	void setNext(wordNode *Node) { wNext = Node; } //set next word node
	wordNode *getNext() { return wNext; }//get next word node
};

