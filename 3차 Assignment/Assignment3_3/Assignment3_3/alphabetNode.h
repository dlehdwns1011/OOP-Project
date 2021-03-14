#pragma once
#include "wordNode.h"
#include <iostream>
#include <cstring>
using namespace std;
class alphabetNode
{
private:
	char a; //initial alphabet
	wordNode* firstNode; //pointer of first word node
	alphabetNode* aNext; //pointer of next alphaber node

public:
	alphabetNode();
	~alphabetNode();
	void setA(char c)	{	a = c;	} //set initial alphabet
	char getA() { return a; } //get initial alphabet
	//set first word node of alphabet node
	void setfirstNode(wordNode* Node)	{	firstNode = Node;	}
	wordNode* getword() { return firstNode; } //get first word node
	void setNext(alphabetNode* Node) {	aNext = Node;} //set next alphabet node
	alphabetNode* getNext() { return aNext; }//get next alphabet node
};

