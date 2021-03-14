#include "ContactList.h"

ContactList::ContactList()
{
	C_head = NULL; //make NULL
}

ContactList::~ContactList()
{//delete all of data in contact linked list
	ContactNode* d = C_head;
	ContactNode* dd = NULL;
	while (d)
	{
		dd = d;
		d = d->getPright();
		delete dd;
	}
}

bool ContactList::findContactNode(char * c)
{//find contact node using real contact
	ContactNode* pCur = C_head;
	while (pCur)
	{
		if (!strcmp(pCur->getContact(), c))
			return true; //found!
		pCur = pCur->getPright();
	}
	return false;//if can not found
}

