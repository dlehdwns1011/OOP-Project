#pragma once
#include <iostream>
#include "Name.h"
#include "GradeList.h"
#include "StudentIDList.h"
#include "ContactList.h"

using namespace std;
class NameList
{
	Node* N_head; //head node in name linked list

public:
	NameList();
	~NameList();

	void setN_head(Node* node) { N_head = node; } //set head node
	Node* getN_head() { return N_head; } //get head node
	void insertNameNode(char* n, char g, char* s, char* c); //insert name node in name linked list
	//find name node using name, id and contact
	Node* findNameNode(char* name, char* id, char* pn);
	//find name node using only name
	Node* findNameNode(char* name);
	//find name node using Id or contact
	Node* findNameNodeusingID(char* id);
	Node* findNameNodeusingContact(char *c);
};

