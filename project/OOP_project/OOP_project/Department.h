#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class DepartmentNode : public Node
{
private:
	char de_name[32]; //name of department

public:
	DepartmentNode();
	~DepartmentNode();
	////virtual function////
	//set and get department name of node 
	virtual void setDname(char* Dname) { strcpy_s(de_name, Dname); }
	virtual char* getDname() { return de_name; }
};