#pragma once
#include <iostream>
#include "StudentID.h"
using namespace std;
class StudentIDList
{
	StudentIDNode* S_head; //head node in student id linked list

public:
	StudentIDList();
	~StudentIDList();

	void setS_head(StudentIDNode* node) { S_head = node; } //set head
	StudentIDNode* getS_head() { return S_head; }//get head
	bool findStudentNode(char* c);//find student id
};

