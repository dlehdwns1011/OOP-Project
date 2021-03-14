#pragma once
#include <iostream>
#include "Card.h"

using namespace std;
class Queue
{
private:
	Card* Head; //head node of Queue
	int size; //Queue size
	int count; //Queue count


public:
	Queue()
	{
		Head = NULL;
		size = 0;
		count = 0;
	}
	~Queue()
	{//delete all of node in Queue
		Card* pCur = Head;
		Card* pCur2;
		while (pCur)
		{
			pCur2 = pCur;
			pCur = pCur->getNext();
			delete pCur2;
		}
	}
	void setSize(int n) { size = n; } //set size of Queue
	void Pc() { count++; } //Queue count++
	void Mc() { count--; } //Queue count--
	bool IsEmpty() 
	{//check Queus is Empty
		if (count == 0)//if empty
			return true;
		else//if not
			return false;
	}
	bool IsFull()
	{//check Queue is Full
		if (size == count)//if Full
			return true;
		else//if not
			return false;
	}
	void Pop(); //pop
	void Push();//push

	void Print();//print

	int Find(int a, int b);//chech function

};

