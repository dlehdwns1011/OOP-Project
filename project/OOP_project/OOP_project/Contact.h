#pragma once
#include <iostream>
class ContactNode
{
	char contact[32]; //contact
	ContactNode* Pright; //next contact pointer
public:
	ContactNode();
	~ContactNode();

	void setContact(char* c) { strcpy_s(contact, c); } //set contact
	void setPright(ContactNode* newNode) { Pright = newNode; } //set next contact
	char* getContact() { return contact; } //get contact
	ContactNode* getPright() { return Pright; } //get next contact node
};

