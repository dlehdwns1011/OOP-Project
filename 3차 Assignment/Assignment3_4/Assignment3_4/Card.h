#pragma once
#include <iostream>

using namespace std;

class Card
{
private:
	int shape; //shape of card
	int num;   //number of care
	Card* pNext; //pointer of next card node

public:
	Card()
	{
		shape = 0;
		num = 0;
		pNext = NULL;
	}
	~Card()
	{

	}
	void setCard(int s, int n) {shape = s ; num = n; } //set data in card node
	int getShape() { return shape; } //get shape of card node
	int getNum() { return num; } //get number of card node
	Card* getNext() //get next card node
	{			return pNext; 	}
	void setNext(Card* newCard) { pNext = newCard; } //set next card node

};

