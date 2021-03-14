#pragma once
#include <iostream>
class GradeNode
{
	int grade; //grade
	GradeNode* Pleft; //next grade node pointer
public:
	GradeNode();
	~GradeNode();
	void setGrade(char g) { grade = (int)g; } //set grade
	void setPleft(GradeNode* newNode) { Pleft = newNode; } //set next grade node
	char getGrade() { return (char)grade; } //get grade
	GradeNode* getPleft() { return Pleft; } //get next grade node
};

