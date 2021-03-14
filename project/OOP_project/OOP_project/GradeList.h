#pragma once
#include <iostream>
#include "Grade.h"
using namespace std;
class GradeList
{
	GradeNode* G_head; //head node in grade linked list
public:
	GradeList();
	~GradeList();

	void setG_head(GradeNode* node) { G_head = node; } //set head node
	GradeNode* getG_head() { return G_head; } //get head node
};

