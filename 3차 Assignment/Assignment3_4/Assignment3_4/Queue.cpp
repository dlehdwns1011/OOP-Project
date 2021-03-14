#include "Queue.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <time.h>


using namespace std;

void Queue::Pop()
{//pop in Queue -> Head is first input in Queue
	if (IsEmpty() == true)
	{//if Queue is empty
		cout << "Queue is Empty!!" << endl;
		return;
	}
	Card* t;
	t = Head; //will be pop
	Head = Head->getNext(); //new head
	int i = t->getShape();
	if (i == 0)//print shape of card will be pop
		cout << "¢¼";
	else if (i == 1)
		cout << "¢À";
	else if (i == 2)
		cout << "¡ß";
	else
		cout << "¢¾";
	cout <<t->getNum() << " is popped" << endl; //print number of card will be pop
	Mc(); //count - 1
	if (IsEmpty() == true) //if Queue is empty
		cout << "Queue is Empty" << endl;
	delete t;

}

void Queue::Push()
{//push in Queue -> tail of Queue is last input in Queue
	if (IsFull() == true)
	{//if Queue is already Full
		cout << "Queue is Full!!" << endl;
		return;
	}
	Card* newCard = new Card; //make new Card node
	int s=0, n=0; 
	while (1)
	{//make shape and number not before
		srand(time(0));
		s = rand() % 4;//make shape range of 0~3
		n = rand() % 13;//make number range of 0~12
		if (Find(s, n+1)) //chech already
			break;
	}
	n++; //make card number
	newCard->setCard(s, n); //set data in card node
	if (Head == NULL)
	{//if empty
		Head = newCard; //new head
		Pc(); //count + 1
		return;
	}
	Card* pCur = Head;
	while (pCur->getNext() != NULL)
	{//moving for input in last of Queue
		pCur = pCur->getNext();
	}
	pCur->setNext(newCard); //insert
	Pc();//count + 1
}

void Queue::Print()
{//print all of Cards in Queue
	if (Head == NULL) //if not exist Queue
		return;
	Card* pCur = Head;
	while (pCur)
	{
		int i = pCur->getShape();
		if (i == 0) //print shape
			cout << "¢¼";
		else if (i == 1)
			cout << "¢À";
		else if (i == 2)
			cout << "¡ß";
		else
			cout << "¢¾";

		cout<< pCur->getNum(); 
		pCur = pCur->getNext();//print number
		if (pCur != NULL)
			cout << " / ";
	}
	cout << endl;
}

int Queue::Find(int a, int b)
{//check already exist card 
	Card* pCur = Head;
	while (pCur)
	{
		if (pCur->getShape() == a && pCur->getNum() == b)
			return 0; //if already exist
		pCur = pCur->getNext();
	}
	return 1; //if not already exist
}