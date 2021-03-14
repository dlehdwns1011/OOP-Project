#pragma once
#include <iostream>
class StudentIDNode
{
	char studentid[32]; //student id
	StudentIDNode* Pfront; //pointer of next student id node
public:
	StudentIDNode();
	~StudentIDNode();
	void setStudentID(char* I) { strcpy_s(studentid, I); } //set id
	void setPfront(StudentIDNode* newNode) { Pfront = newNode; }//set next node
	char* getStudentID() { return studentid; }//get id
	StudentIDNode* getPfront() { return Pfront; }//get next node
};

