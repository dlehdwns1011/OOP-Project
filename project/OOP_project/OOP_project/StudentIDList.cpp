#include "StudentIDList.h"



StudentIDList::StudentIDList()
{
	S_head = NULL; //make NULL
}


StudentIDList::~StudentIDList()
{//delete all of data in student id linked list
	StudentIDNode* d = S_head;
	StudentIDNode* dd = NULL;
	while (d)
	{
		dd = d;
		d = d->getPfront();
		delete dd;
	}
}

bool StudentIDList::findStudentNode(char * c)
{//find student id node in student liked list
	StudentIDNode* pCur = S_head; //get head
	while (pCur)
	{
		if (!strcmp(pCur->getStudentID(), c))
			return true; //if same id, return id node
		pCur = pCur->getPfront();
	}
	return false; //if can not found
}
