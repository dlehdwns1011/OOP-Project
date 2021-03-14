#include "DepartmentList.h"


DepartmentList::DepartmentList()
{
	D_head = NULL;
	D_tail = NULL; //make NULL
}

DepartmentList::~DepartmentList()
{//delete all of department node in linke list
	Node* d = D_head;
	D_tail->setPnext(NULL);
	Node* dd = NULL;
	while (d)
	{
		dd = d;
		d = d->getPnext();
		delete dd;
	}
}

void DepartmentList::Insert(char * d)
{
	Node* Dnode = Find(d);
	if (Dnode == NULL)
	{//not exist D node
		Node* newDnode = new DepartmentNode; //make department node
		newDnode->setDname(d);//set department name
		if (D_head == NULL)
		{//if empty Department liked list
			D_head = newDnode;
			D_tail = newDnode; //set head and tail
		}
		else
		{//not empty
			Node* pCur = D_head;
			Node* ppCur = NULL;
			if (D_head == D_tail)
			{//if exist only one department node
				if (strcmp(D_head->getDname(), newDnode->getDname()) > 0)
				{//case of make new head
					D_head = newDnode; //new head 
					D_head->setPnext(D_tail);
					D_tail->setPprev(D_head);
					D_tail->setPnext(D_head);
					D_head->setPprev(D_tail); //new link
				}
				else
				{//case of make new tail
					D_tail = newDnode; //new tail
					D_head->setPnext(D_tail);
					D_tail->setPprev(D_head);
					D_tail->setPnext(D_head);
					D_head->setPprev(D_tail); //new link
				}
				return;//success
			}
			//if exist two or more department node
			while (pCur != D_tail)
			{//find position can insert
				if (strcmp(pCur->getDname(), newDnode->getDname()) > 0)
				{
					break;
				}
				ppCur = pCur;
				pCur = pCur->getPnext();
			}
			if (strcmp(pCur->getDname(), newDnode->getDname()) < 0)
			{//case of make new tail
				pCur->setPnext(newDnode);
				newDnode->setPprev(pCur);
				newDnode->setPnext(D_head);
				D_head->setPprev(newDnode); //new link
				D_tail = newDnode;//change tail
				return; 
			}
			if (ppCur != NULL)
			{//insert in middle
				newDnode->setPprev(ppCur);
				ppCur->setPnext(newDnode); //new link
			}
			else
			{//insert in head
				D_head = newDnode; //change head
				D_tail->setPnext(D_head);
				D_head->setPprev(D_tail);
			}
			newDnode->setPnext(pCur);
			pCur->setPprev(newDnode); //new link
		}

	}
}

Node* DepartmentList::Find(char * D_name)
{//find department node
	if (D_head == NULL)
		return NULL; //if not exist linked list
	Node* pCur = D_head;
	if (!strcmp(D_head->getDname(), D_name))
		return pCur; //if head is node that want to find
	pCur = pCur->getPnext();
	while (pCur != D_head && pCur != NULL)
	{
		if (!strcmp(D_name, pCur->getDname()))
			return pCur; //found!
		pCur = pCur->getPnext();
	}
	return NULL; //if can not found
}

