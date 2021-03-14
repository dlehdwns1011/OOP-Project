#include "linkedList.h"
#include "alphabetNode.h"
#include "wordNode.h"
#include <iostream>
#include <fstream>

using namespace std;

linkedList::linkedList()
{
	pHead = NULL;
}


linkedList::~linkedList()
{
	alphabetNode* a = pHead;
	alphabetNode* pa = NULL;
	wordNode* w = NULL; wordNode* pw = NULL;
	while (a)
	{//delete all of linked list
		pa = a;
		w = a->getword();
		while (w)
		{
			pw = w;
			w = w->getNext();
			delete pw;
		}
		a = a->getNext();
		delete pa;
	}
}

void linkedList::manager()
{//manager function
	if (pHead == NULL) 
		setANode(); //if not exist linked list
	ifstream cin; //declare input file
	char line[100];
	cin.open("input.txt"); //open file
	if (cin.fail())
	{//if file is not exist
		cout << "Not exist input file" << endl;
		return;
	}
	while (cin.getline(line, 100)) //get word
		insertnode(line); //insert word node fucntion
	printLinkedList(); //print function
	cin.close();

}

void linkedList::insertnode(char* c)
{//insert node had word
	alphabetNode* node; 
	node = SearchAnode(c[0]); //search alphabet node had same initial
	if (node->getword() == NULL)
	{//if first node in wordNode
		wordNode* NEW = new wordNode; //make word Node
		NEW->setword(c); //set data(word)
		node->setfirstNode(NEW);//set linked list
		return;
	}
	//if not first node
	wordNode* pCur = node->getword();
	wordNode* ppCur = NULL;
	wordNode* pNew = new wordNode; //make new node
	pNew->setword(c); //set data(word)
	while (strcmp(pCur->getword(), c) < 0)
	{//find position can insert word Node
		ppCur = pCur;
		pCur = pCur->getNext();
		if (pCur == NULL)
			break;
	}
	if(ppCur != NULL)
		ppCur->setNext(pNew); //new linked
	pNew->setNext(pCur);
	if (pCur == node->getword()) 
		node->setfirstNode(pNew);


}

void linkedList::printLinkedList()
{//print all of linked list
	alphabetNode* node = pHead; //to move alphabetnode
	wordNode* pCur; //to move wordnode
	while (node)
	{//from first to end is alphabet node
		cout << node->getA(); //print initial alphabet
		if (node->getword() != NULL)
		{
			cout << " -> ";
			pCur = node->getword();
			while (pCur->getNext())
			{//print all of word node in one alphabet
				cout << pCur->getword() << " -> ";
				pCur = pCur->getNext();
			}
			cout << pCur->getword();
		}
		node = node->getNext(); //next alphabet
		cout << endl;
	}
}
