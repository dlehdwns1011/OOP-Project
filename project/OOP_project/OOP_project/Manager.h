#pragma once
#include <iostream>
#include "Node.h"
#include "DepartmentList.h"
#include "NameList.h"
#include "GradeList.h"
#include "StudentIDList.h"
#include "ContactList.h"
#include <fstream>

using namespace std;

class Manager
{
private:
	DepartmentList * D_list;
	ContactList* C_list;
	GradeList* G_list;
	NameList* N_list;
	StudentIDList* S_list; //declare each linked list

public:
	Manager();
	~Manager();

	void ReadCommand(const char* command); //read command
	bool LOAD(); //load
	int ADD(); //add
	int UPDATE(); //update
	bool MODIFY_DEPARTMENT(char* oldD, char* newD); //modify department
	bool DELETE_DEPARTMENT(char* delD); //delete department
	void PRINT(); //print all of information
	void PRINT(char* Dname); //print date of department
	void PRINT_STUDENT_ID();//print student id
	void PRINT_CONTACT(); //print contact
	bool FIND_NAME(char* name); //find name or first name
	bool SAVE(char* filename); //save all of informationin text file
	bool SAVE() { return false; } //if not insert parameter
};

