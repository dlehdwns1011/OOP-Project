#pragma once
#include <iostream>
#include "Contact.h"
using namespace std;
class ContactList
{
	ContactNode* C_head; //head node in contact linked list
public:
	ContactList();
	~ContactList();
	ContactNode* getC_head() { return C_head; } //get head node
	void setC_head(ContactNode* node) { C_head = node; }//set head node
	bool findContactNode(char* c); //find contact function
};

