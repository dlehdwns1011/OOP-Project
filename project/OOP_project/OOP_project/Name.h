#pragma once
#include <iostream>
#include "GradeList.h"
#include "StudentIDList.h"
#include "ContactList.h"
#include "Node.h"

using namespace std;
class NameNode : public Node
{
private:
	GradeNode * Pleft; //pointer of grade node
	StudentIDNode *Pfront; //pointer of student id node
	ContactNode *Pright; //pointer of contact node
	char name[32]; //name
public:
	NameNode();
	~NameNode();
	////virtual function////
	virtual void setname(char* newname) {strcpy_s(name, newname);} //set name
	virtual char* getname() { return name; } //get name
	virtual void setG(GradeNode* node) { Pleft = node; } //set grade node
	virtual void setS(StudentIDNode* node) { Pfront = node; } //set student id node
	virtual void setC(ContactNode* node) { Pright = node; }//set contact node
	virtual GradeNode * getG() { return Pleft; }//get grade node 
	virtual StudentIDNode * getS() { return Pfront;	}//get student id node
	virtual ContactNode * getC() { return Pright; }//get contact node
};

