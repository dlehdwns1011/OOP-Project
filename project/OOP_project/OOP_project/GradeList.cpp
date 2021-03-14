#include "GradeList.h"



GradeList::GradeList()
{
	G_head = NULL; //make NULL
}

GradeList::~GradeList()
{//delete all of data in grade linked list
	GradeNode* d = G_head;
	GradeNode* dd = NULL;
	while (d)
	{
		dd = d;
		d = d->getPleft();
		delete dd;
	}
}
