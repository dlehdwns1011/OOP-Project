#pragma once
#include <iostream>
#include "GradeList.h"
#include "StudentIDList.h"
#include "ContactList.h"

using namespace std;

class Node
{
private:
	Node * Pnext;
	Node *Pprev;
	Node *Pup;
	Node *Pdown;  //pointer of each direction
	 
public:
	Node();
	~Node();
	////virtual function////
	//set and get pointer function
	virtual void setPnext(Node* newNode) { Pnext = newNode; }
	virtual void setPprev(Node* newNode) { Pprev = newNode; }
	virtual void setPup(Node* newNode) { Pup = newNode; }
	virtual void setPdown(Node* newNode) { Pdown = newNode; }
	virtual Node* getPnext() { return Pnext; }
	virtual Node* getPprev() { return Pprev; }
	virtual Node* getPup() { return Pup; }
	virtual Node* getPdown() { return Pdown; }

	//virtual function of DepartmentNode and List
	virtual void setDname(char* Dname) {}
	virtual char* getDname() { return NULL; }

	//virtual function of NameNode and List
	virtual void setname(char* newname) {}
	virtual char* getname() { return NULL; }
	virtual void setG(GradeNode* node) {}
	virtual void setS(StudentIDNode* node) {}
	virtual void setC(ContactNode* node) {}
	virtual GradeNode * getG() { return NULL; }
	virtual StudentIDNode * getS() { return NULL; }
	virtual ContactNode * getC() { return NULL; }

};