#include "NameList.h"


NameList::NameList()
{
	N_head = NULL; //make NULL
}


NameList::~NameList()
{//delete all of data in name linked list
	Node* d = N_head;
	Node* dd = NULL;
	while (d)
	{
		dd = d;
		d = d->getPnext();
		delete dd;
	}
}

void NameList::insertNameNode(char* n, char g, char* s, char* c)
{//insert name node in name linked list
	Node* node = new NameNode; //make new name node
	node->setname(n); //set name in node

	GradeNode* Gnode = new GradeNode; //make grade node
	Gnode->setGrade(g); //set grade
	StudentIDNode* Snode = new StudentIDNode; //make student id node
	Snode->setStudentID(s);//set student id 
	ContactNode* Cnode = new ContactNode; //make contact node
	Cnode->setContact(c); //set contact node

	node->setC(Cnode);
	node->setG(Gnode);
	node->setS(Snode); //link name node with each node 

	Node* ppCur = NULL; 
	Node* pCur = N_head; //get head node in Name linked list
	if (pCur == NULL)
	{//if not exist linked list
		N_head = node;
	}
	else
	{//exist linked list
		while (pCur)
		{//find position can insert name node
			if (strcmp(pCur->getname(), node->getname()) > 0)
				break;
			ppCur = pCur;
			pCur = pCur->getPnext();
		}
		if (ppCur != NULL)
		{//exist before node
			ppCur->setPnext(node);
			node->setPprev(ppCur);//new link
			ppCur->getC()->setPright(node->getC());
			ppCur->getG()->setPleft(node->getG());
			ppCur->getS()->setPfront(node->getS()); //new link each node
		}
		if (pCur != NULL)
		{//if last node
			node->setPnext(pCur);
			pCur->setPprev(node);//new link
			node->getC()->setPright(pCur->getC());
			node->getG()->setPleft(pCur->getG());
			node->getS()->setPfront(pCur->getS());//new link each node
		}
		if (ppCur == NULL)
		{//if insert in head
			N_head = node;
		}
	}
}

Node * NameList::findNameNode(char * name, char *id, char *pn)
{//find name node in name linked list using name, id and contact
	Node* pCur = N_head; //get head node
	while (pCur)
	{//find 
		if (!strcmp(name, pCur->getname()))
		{//if same name
			if(!strcmp(pCur->getS()->getStudentID(),id)
				&& !strcmp(pCur->getC()->getContact(),pn))
				return pCur;//if same id, contact, return name node
		}
		pCur = pCur->getPnext();
	}
	return NULL; //if can not found
}

Node * NameList::findNameNode(char * name)
{//find name node in name linked list using name
	Node* pCur = N_head;//get head node
	while (pCur)
	{//find
		if (!strcmp(name, pCur->getname()))
			return pCur;//if same name, return name node
		pCur = pCur->getPnext();
	}
	return NULL; //if can not found
}

Node * NameList::findNameNodeusingID(char * id)
{//find namenode using id
	Node* pCur = N_head;
	while (pCur)
	{
		if (!strcmp(pCur->getS()->getStudentID(), id))
			return pCur; //if same id, return name node
		pCur = pCur->getPnext();
	}
	return NULL;
}

Node * NameList::findNameNodeusingContact(char * c)
{//find namenode using contact
	Node* pCur = N_head;
	while (pCur)
	{
		if (!strcmp(pCur->getC()->getContact(), c))
			return pCur;//if same contact, return name node
		pCur = pCur->getPnext();
	}
	return NULL;
}
