#pragma once
#include <iostream>
#include "Department.h"
#include "NameList.h"
#include "GradeList.h"
#include "StudentIDList.h"
#include "ContactList.h"

using namespace std;
class DepartmentList
{
	Node* D_head; //head node in linked list
	Node* D_tail; //tail node in linked list
public:
	DepartmentList();
	~DepartmentList();

	//get head or tail node
	Node* getD_head() { return D_head; }
	Node* getD_tail() { return D_tail; }
	void setD_head(Node* node) { D_head = node; }
	void setD_tail(Node* node) { D_tail = node; }
	void Insert(char* d);//insert department node
	Node* Find(char* D_name); //find department node
};

