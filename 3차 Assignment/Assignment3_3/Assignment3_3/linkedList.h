#pragma once
#include <iostream>
#include "linkedList.h"
#include "alphabetNode.h"
#include "wordNode.h"
#include <iostream>

class linkedList
{
private:
	alphabetNode* pHead; //Head node of linked list

public:
	linkedList();
	~linkedList();

	void manager();
	void insertnode(char* c); //insert node of word
	alphabetNode* SearchAnode(char c)
	{//search node have alphabet data
		if (pHead == NULL)
			return NULL;
		alphabetNode* pCur = pHead;
		while (pCur)
		{
			if ((int)c == (int)pCur->getA())
				break;
			pCur = pCur->getNext();
		}
		if (pCur == NULL)
			return NULL;
		else
			return pCur;

	}
	void printLinkedList(); //print all of node in linked list
	void setANode()
	{//make alphabet Node
		alphabetNode* node = new alphabetNode;
		node->setA((char)97); //meka a node
		pHead = node; //set head node
		
		for (int i = 98; i <= 122; i++)
		{//make node from b to z
			alphabetNode* node2 = new alphabetNode;
			node2->setA((char)i);
			while (node->getNext())
				node = node->getNext();
			node->setNext(node2);
		}

	}
};

