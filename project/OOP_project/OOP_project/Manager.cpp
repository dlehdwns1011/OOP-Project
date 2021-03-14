#include "Manager.h"
#include "iostream"
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

Manager::Manager()
{
	D_list = new DepartmentList();
	C_list = new ContactList();
	G_list = new GradeList();
	N_list = new NameList();
	S_list = new StudentIDList(); //declare and make List
	ofstream fout;
	fout.open("Log.txt", ios::trunc); 
	fout.close(); //make Log text file and make empty
}

Manager::~Manager()
{
	delete D_list;
	delete C_list;
	delete G_list;
	delete N_list;
	delete S_list; //delete object
}

void Manager::ReadCommand(const char* command)
{//Read Command function
	ofstream fout;
	fout.open("Log.txt", ios::app); //open log file
	ifstream fin;
	char c[200]; char** temp = new char*[100]; char t[200];
	fin.open(command); //open command file
	while (fin.getline(c, 200))
	{//get each command
		cout<<"[" << c << "]"<<endl;
		fout << "[" << c << "]" << endl; //print Command
		if (!strcmp(c, "LOAD"))
		{//LOAD
			if (LOAD() == false)
			{//if not exist information text file
				cout << "Error code - 100" << endl<<endl;
				fout << "Error code - 100" << endl<<endl;
				return;
			}
			fout << "Success" << endl << endl;
			cout << "Success" << endl << endl;//Success LOAD
			continue;
		}
		else if (!strcmp(c, "ADD"))
		{//ADD
			int A = ADD();
			if (A == 0)
			{//if not exit add information text file
				cout << "Error code - 200" << endl<< endl;
				fout << "Error code - 200" << endl<<endl;
			}
			else if (A == 1)
			{//if exist wrong data
				cout << "Error code - 200 - 1" << endl<<endl;
				fout << "Error code - 200 - 1" << endl<<endl;
			}
			else if (A == 2)
			{//Success ADD
				fout << "Success" << endl << endl;
				cout << "Success" << endl << endl;
			}
			continue;
		}
		else if (!strcmp(c, "UPDATE"))
		{//UPDATE
			int U = UPDATE();
			if (U == 0)
			{//if not exist update information text file
				cout << "Error code - 300" << endl<<endl;
				fout << "Error code - 300" << endl<<endl;
			}
			else if (U == 1)
			{//if exist wrong data
				cout << "Error code - 300 - 1" << endl<<endl;
				fout << "Error code - 300 - 1" << endl<<endl;
			}
			else if (U == 2)
			{//if not exist data will be updated
				cout << "Error code - 300 - 2" << endl<<endl;
				fout << "Error code - 300 - 2" << endl<<endl;
			}
			else
			{//Success UPDATE
				fout << "Success" << endl << endl;
				cout << "Success" << endl << endl;
			}
			cout << endl;
			fout << endl;
			Node * DD = D_list->getD_head();
			Node * nD = NULL;
			while (DD != D_list->getD_tail())
			{//if Department Node dont have student
				nD = DD->getPnext();
				if (DD->getPdown() == NULL)
				{//Delete Department
					DELETE_DEPARTMENT(DD->getDname());
				}
				DD = nD;
			}
			continue;
		}
		else if (!strcmp(c, "PRINT"))
		{//PRINT + default
			PRINT(); //print all of information
			continue;
		}
		else if (!strcmp(c, "EXIT"))
		{//EXIT
			fout.close();
			fin.close(); //file close
			delete[] temp; //clear memory
			return;
		}
		strcpy_s(t, c);
		strtok_s(c, " ", temp); //divide command
		if(!strcmp(c, "PRINT"))
		{//PRINT Department
			strcpy_s(t, t + 6);
			char  d[100]; //make department
			strcpy_s(d, strtok_s(t, "\n", temp));
			PRINT(d);
		}
		else if (!strcmp(c, "MODIFY_DEPARTMENT"))
		{//MODIFY_DEPARTMENT
			char  d[100], d2[100];
			strcpy_s(t, t + 18);
			strcpy_s(d, strtok_s(t, " ", temp)); //old department
			strcpy_s(d2, strtok_s(NULL, "\n", temp));//new department
			if (MODIFY_DEPARTMENT(d, d2) == false)
			{//if not exist department
				cout << "Error code - 400" << endl;
				fout << "Error code - 400" << endl;
			}
			else
			{//Success MODIFY
				fout << "Success" << endl;
				cout << "Success" << endl;
			}
			cout << endl;
			fout << endl;
		}
		else if (!strcmp(c, "DELETE_DEPARTMENT"))
		{//DELETE_DEPARTMENT
			char d[50];
			strcpy_s(t, t + 18);
			strcpy_s(d, strtok_s(t, "\n", temp));
			if (DELETE_DEPARTMENT(d) == false)
			{//if not exist department
				cout << "Error code - 500" << endl;
				fout << "Error code - 500" << endl;
			}
			else
			{//Success DELETE
				cout << "Success" << endl;
				fout << "Success" << endl;
			}
			cout << endl;
			fout << endl;
		}
		else if (!strcmp(c, "PRINT_STUDENT_ID"))
		{//PRINT using Student id
			PRINT_STUDENT_ID();
		}
		else if (!strcmp(c, "PRINT_CONTACT"))
		{//PRINT using contact
			PRINT_CONTACT();
		}
		else if (!strcmp(c, "FIND_NAME"))
		{//FIND_NAME
			char d[50]; 
			strcpy_s(t, t + 10);
			strcpy_s(d, strtok_s(t, "\n", temp));//make name
			if (FIND_NAME(d) == false)
			{//if not exist information had name or first name
				cout << "Error code - 900" << endl;
				fout << "Error code - 900" << endl;
			}
			cout << endl;
			fout << endl;
		}
		else if (!strcmp(c, "SAVE"))
		{//SAVE
			char d[50];
			if(t[4] == '\0')
			{//if not insert parameter
				cout << "Error code - 1000" << endl;
				fout << "Error code - 1000" << endl;
			}
			else
			{
				strcpy_s(t, t + 5);
				strcpy_s(d, strtok_s(t, "\n", temp));
				if (SAVE(d) == false)
				{//if not insert parameter
					cout << "Error code - 1000" << endl;
					fout << "Error code - 1000" << endl;
				}
				else
				{//Succes SAVE
					cout << "Success" << endl << endl;
					fout << "Success" << endl << endl;
				}
			}
			cout << endl;
			fout << endl;
		}
		else
		{//wrong instruction
			cout << "Error code - 000" << endl<<endl;
			fout << "Error code - 000" << endl<<endl;
		}
	}

}

bool Manager::LOAD()
{//LOAD function
	char c[256]; char** temp = new char*[256];
	ifstream fin;
	fin.open("Information.txt"); //file open
	if (fin.fail())//if not exist file
		return false;
	char D[50];	char N[50]; char G[2];
	char ID[50]; char PN[50];
	while (fin.getline(c, 256))
	{//get each information
		strcpy_s(D,strtok_s(c, "\t",temp)); //Department
		strcpy_s(N, strtok_s(NULL, "\t",temp)); //Name
		strcpy_s(G, strtok_s(NULL, "\t",temp)); //Grade
		strcpy_s(ID, strtok_s(NULL, "\t",temp));//Student ID
		strcpy_s(PN, strtok_s(NULL, "\n",temp));//Contact
		D_list->Insert(D); //make and insert department node
		N_list->insertNameNode(N, G[0], ID, PN);
		//make and insert name node
		Node* departnode;
		departnode = D_list->Find(D); //find Department Node
		Node* namenode;
		namenode = N_list->findNameNode(N,ID,PN); //find Name node
		Node* pCur = departnode->getPdown(); 
		Node* ppCur = NULL;
		while (pCur)
		{//find position can insert name node under the department node
			if (strcmp(pCur->getname(), namenode->getname()) > 0)
			{
				break;
			}
			ppCur = pCur;
			pCur = pCur->getPdown();
		}
		if (pCur == NULL && ppCur == NULL)
		{//under the department node is empty case
			departnode->setPdown(namenode);
			namenode->setPup(departnode);//make link
		}
		else if(ppCur == NULL && pCur != NULL)
		{//already exist node but insert direct under the department Node
			namenode->setPup(departnode);
			departnode->setPdown(namenode);
			namenode->setPdown(pCur);
			pCur->setPup(namenode); //make and modify link
		}
		else
		{//insert middle or end of Node
			namenode->setPup(ppCur);
			ppCur->setPdown(namenode);//make and modify link
			if (pCur != NULL)
			{//if insert in end of Node
				namenode->setPdown(pCur);
				pCur->setPup(namenode);//make and modify link
			}
		}
	}
	delete[] temp; //delete memory
	fin.close(); //file close
	C_list->setC_head(N_list->getN_head()->getC());
	G_list->setG_head(N_list->getN_head()->getG());
	S_list->setS_head(N_list->getN_head()->getS());
	//modify each head node
	return true; //success
}

int Manager::ADD()
{//ADD function
	int flag = 2;
	ifstream finA;
	finA.open("Add_information.txt"); //file open
	if(finA.fail())//if not exist file
		return 0;
	char c[100]; char** temp = new char*[256];
	char D[50];	char N[50]; char G[2];
	char ID[50]; char PN[50];
	while (finA.getline(c, 100))
	{//get each information
		strcpy_s(D, strtok_s(c, "\t", temp));//department
		strcpy_s(N, strtok_s(NULL, "\t", temp));//name
		strcpy_s(G, strtok_s(NULL, "\t", temp));//grade
		strcpy_s(ID, strtok_s(NULL, "\t", temp));//student id
		strcpy_s(PN, strtok_s(NULL, "\n", temp));//contact
		Node* Cur = N_list->findNameNode(N, ID, PN);//find name node
		if (Cur != NULL)//if already exist name Node
		{
			flag = 1;
			continue;
		}
		if (C_list->findContactNode(PN) == true)
		{
			flag = 1;
			continue;
		}

		D_list->Insert(D); //make and insert department node
		N_list->insertNameNode(N, G[0], ID, PN); //make and insert name node
		Node* departnode;
		departnode = D_list->Find(D); //find department node
		Node* namenode;
		namenode = N_list->findNameNode(N, ID,PN);//find name node
		Node* pCur = departnode->getPdown();
		Node* ppCur = NULL;

		while (pCur)
		{//find position can insert name node under the department node
			if (strcmp(pCur->getname(), namenode->getname()) > 0)
			{
				break;
			}
			ppCur = pCur;
			pCur = pCur->getPdown();
		}
		if (pCur == NULL && ppCur == NULL)
		{//under the department node is empty case
			departnode->setPdown(namenode);
			namenode->setPup(departnode);//make link
		}
		else if (ppCur == NULL && pCur != NULL)
		{//already exist node but insert direct under the department Node
			namenode->setPup(departnode);
			departnode->setPdown(namenode);
			namenode->setPdown(pCur);
			pCur->setPup(namenode); //make and modify link
		}
		else
		{//insert middle or end of Node
			namenode->setPup(ppCur);
			ppCur->setPdown(namenode);//make and modify link
			if (pCur != NULL)
			{//if insert in end of Node
				namenode->setPdown(pCur);
				pCur->setPup(namenode);//make and modify link
			}
		}
	}
	delete[] temp; //delete memory
	finA.close();//file close
	return flag; //success
}

int Manager::UPDATE()
{//UPDATE fucntion
	ifstream finu;
	finu.open("Update_information.txt");//file open
	if (finu.fail())//if not exist file
		return 0;
	char c[100]; char** temp = new char*[256];
	char D[50];	char N[50]; char G[2];
	char ID[50]; char PN[50];
	while (finu.getline(c, 100))
	{//get eact information 
		strcpy_s(D, strtok_s(c, "\t", temp)); //department
		strcpy_s(N, strtok_s(NULL, "\t", temp));//name
		strcpy_s(G, strtok_s(NULL, "\t", temp));//grade
		strcpy_s(ID, strtok_s(NULL, "\t", temp));//student id
		strcpy_s(PN, strtok_s(NULL, "\n", temp));//contact

		Node* unode = NULL;
		

		unode = N_list->findNameNode(N); //find name node using name
		if (unode == NULL)
		{//if can not find name 
			delete[] temp; //delete memory
			finu.close(); //file close
			return 2;
		}

		if (strcmp(unode->getC()->getContact(), PN))
		{//update contact
			if (C_list->findContactNode(PN) == false)
				unode->getC()->setContact(PN);//can update contact
			else
			{//exist already contact
				delete[] temp; //delete memory
				finu.close();//file close
				return 1;
			}
			
		}
		if (strcmp(unode->getS()->getStudentID(), ID))
		{//update department and student id of student
			Node *ppCur = unode->getPup();
			Node *nCur = unode->getPdown();
			unode->getS()->setStudentID(ID); //change student id
			//move new link in updated department node
			if (nCur != NULL)
			{
				ppCur->setPdown(nCur);
				nCur->setPup(ppCur);//new link 
			}
			else
				ppCur->setPdown(NULL);
		}
		else
		{//not need to update department and student id of student
			continue;
		}
		Node* departnode = D_list->Find(D); //find updated department node
		Node* pCur = D_list->Find(D)->getPdown();
		Node *ppCur = NULL;
		while (pCur)
		{//find position can insert under the new department
			if (strcmp(pCur->getname(), unode->getname()) > 0)
			{
				break;
			}
			ppCur = pCur;
			pCur = pCur->getPdown();
		}
		if (ppCur == NULL && pCur != NULL)
		{//already exist node but insert direct under the department Node
			unode->setPup(departnode);
			departnode->setPdown(unode);
			unode->setPdown(pCur);
			pCur->setPup(unode);//make and modify link
		}
		else
		{//insert middle or end of Node
			unode->setPup(ppCur);//make and modify link
			ppCur->setPdown(unode);
			if (pCur != NULL)
			{//if insert in end of Node
				unode->setPdown(pCur);
				pCur->setPup(unode);//make and modify link
			}
		}

	}
	delete[] temp; //delete memory
	finu.close(); //file close
	return 3; //success
}

bool Manager::MODIFY_DEPARTMENT(char* oldD, char * newD)
{//MODIFY_DEPARTMENT function
	Node* oldnode,* newnode;
	oldnode = D_list->Find(oldD); //find old department node
	newnode = D_list->Find(newD); //find new department node
	if (oldnode == NULL)//if not exist department wiil be modified
		return false;

	if (newnode == NULL)
	{//if not exist new department
		oldnode->setDname(newD);//change department name
		Node* pCur = D_list->getD_head();
		Node* ppCur = D_list->getD_tail();
		Node* nCur = pCur->getPnext();
		Node* p = D_list->getD_head();

		//new link without oldnode
		if (pCur == oldnode)//if oldnode is head node
			ppCur->setPnext(nCur);
		else
		{//else
			ppCur = pCur;
			pCur = pCur->getPnext();
			nCur = pCur->getPnext();//pointer
			while (pCur != D_list->getD_head())
			{//find prev node and next node for new link
				if (pCur == oldnode)
					break;
				ppCur = pCur;
				pCur = pCur->getPnext();
				nCur = pCur->getPnext();
			}
			ppCur->setPnext(nCur);
		}
		if (strcmp(pCur->getDname(), p->getDname()) < 0)
		{//change head node
			D_list->getD_tail()->setPnext(pCur);
			pCur->setPnext(p);
			D_list->setD_head(pCur);
			return true;
		}
		//else
		p = p->getPnext();
		while (p != D_list->getD_head())
		{
			if (strcmp(p->getDname(), pCur->getDname()) > 0)
				break;
			ppCur = p;
			p = p->getPnext();
		}
		ppCur->setPnext(pCur);
		pCur->setPnext(p);
		if (p == D_list->getD_head())//if need to change tail node
			D_list->setD_tail(pCur);
	}
	else
	{//if already exist department
		Node* pD = oldnode->getPprev();
		Node* nD = oldnode->getPnext();
		pD->setPnext(nD);
		nD->setPprev(pD);//make new link can delete old department
		Node* pCur = oldnode->getPdown();
		Node* nCur = NULL;
		delete oldnode; //delete department node
		Node* pCur2;
		while (pCur)
		{//insert name node from existed under the old department
		//to under the new department 
			nCur = pCur->getPdown();
			Node * ppCur2 = NULL;
			Node * nCur2 = NULL;
			pCur2 = newnode->getPdown();
			while (pCur2)
			{//find position can insert
				if (strcmp(pCur2->getname(), pCur->getname()) > 0)
				{
					break;
				}
				ppCur2 = pCur2;
				pCur2 = pCur2->getPdown();
			}
			if (ppCur2 == NULL)
			{//already exist node but insert direct under the department Node
				newnode->setPdown(pCur);
				pCur->setPup(newnode);
				pCur->setPdown(pCur2);
				pCur2->setPup(pCur);//make and modify link
			}
			else
			{//insert middle or end of Node
				ppCur2->setPdown(pCur);
				pCur->setPup(ppCur2);
				pCur->setPdown(NULL);//make and modify link
				if (pCur2 != NULL)
				{//if insert in end of Node
					pCur->setPdown(pCur2);
					pCur2->setPup(pCur);//make and modify link
				}
			}
			pCur = nCur; //move node
		}
	}


	return true; //success
}

bool Manager::DELETE_DEPARTMENT(char * delD)
{//DELETE function
	Node* pCur = D_list->Find(delD); //find department node will be deleted
	if(pCur == NULL)
		return false; //if not exist department
	if (pCur == D_list->getD_head())
	{//delete head node
		D_list->getD_tail()->setPnext(pCur->getPnext());
		D_list->setD_head(pCur->getPnext());
	}
	else
	{//else
		Node* ppCur = D_list->getD_head();
		while (ppCur->getPnext() != pCur)
			ppCur = ppCur->getPnext();
		ppCur->setPnext(pCur->getPnext());
		if (pCur == D_list->getD_tail())
			D_list->setD_tail(ppCur);
	}

	Node* pCur2 = pCur->getPdown(); //get name node under the department node
	Node* ppCur2 = NULL;
	Node* nCur2 = NULL;
	Node* dCur2 = NULL;
	delete pCur; //delete department node
	while(pCur2)
	{//delete name node had delete department
		ppCur2 = pCur2->getPprev();
		nCur2 = pCur2->getPnext();
		if (pCur2 == N_list->getN_head())
		{//if deleted node is head of name linked list
			N_list->setN_head(pCur2->getPnext());
			//change head of name linked list
		}
		if (ppCur2 != NULL)
		{//if exist node before deleted node
			ppCur2->setPnext(nCur2);
			ppCur2->getG()->setPleft(nCur2->getG());
			ppCur2->getC()->setPright(nCur2->getC());
			ppCur2->getS()->setPfront(nCur2->getS()); //new link
		}
		if (nCur2 != NULL)
		{//if exist node next deleted node
			nCur2->setPprev(ppCur2);
			ppCur2->getG()->setPleft(nCur2->getG());
			ppCur2->getC()->setPright(nCur2->getC());
			ppCur2->getS()->setPfront(nCur2->getS()); //new link
		}
		dCur2 = pCur2;//store temp to delete
		pCur2 = pCur2->getPdown();  //move next name node
		delete dCur2->getC();
		delete dCur2->getG();
		delete dCur2->getS(); //delete information node
		delete dCur2; //delete name node
	}

	return true; //success
}

void Manager::PRINT()
{//PRINT all of information function
	ofstream fout;
	fout.open("Log.txt", ios::app);//file open
	Node* pCur = D_list->getD_head(); //get head
	if (pCur == NULL)
	{//if not exist linekd list
		cout << "Error code - 600" << endl<<endl;
		fout << "Error code - 600" << endl<<endl;
		fout.close();
		return;
	}
	Node* N;

	while (pCur != D_list->getD_tail())
	{//moving node

		N = pCur->getPdown();
		while (N->getPdown())
			N = N->getPdown();
		while (N != pCur)
		{
			cout << pCur->getDname() << "/"; //print department
			cout << N->getname() << "/";//name
			cout << N->getG()->getGrade() << "/";//grade
			cout << N->getS()->getStudentID() << "/";//id
			cout << N->getC()->getContact() << endl;//contact
													   //print file
			fout << pCur->getDname() << "/";
			fout << N->getname() << "/";
			fout << N->getG()->getGrade() << "/";
			fout << N->getS()->getStudentID() << "/";
			fout << N->getC()->getContact() << endl;
			N = N->getPup(); //go to before node
		}
		pCur = pCur->getPnext();
	}
	N = pCur->getPdown();
	while (N->getPdown())
		N = N->getPdown();
	while (N != pCur)
	{
		cout << pCur->getDname() << "/"; //print department
		cout << N->getname() << "/";//name
		cout << N->getG()->getGrade() << "/";//grade
		cout << N->getS()->getStudentID() << "/";//id
		cout << N->getC()->getContact() << endl;//contact
												//print file
		fout << pCur->getDname() << "/";
		fout << N->getname() << "/";
		fout << N->getG()->getGrade() << "/";
		fout << N->getS()->getStudentID() << "/";
		fout << N->getC()->getContact() << endl;
		N = N->getPup(); //go to before node
	}
	pCur = pCur->getPnext();

	cout << endl;
	fout << endl;
	fout.close(); //file close
}

void Manager::PRINT(char* Dname)
{//print name node under the Department
	ofstream fout; 
	fout.open("Log.txt", ios::app);//file open
	if (D_list->getD_head() == NULL)
	{//if not exist linked list
		cout << "Error code - 600 - 1" << endl << endl;
		fout << "Error code - 600 - 1" << endl << endl; //error
		fout.close(); //file close
		return;
	}
	Node* pCur = D_list->Find(Dname); //find department node
	if (pCur == NULL) 
	{//if not exist department
		cout << "Error code - 600 - 2" << endl<<endl;
		fout << "Error code - 600 - 2" << endl<<endl; //error
		fout.close(); //file close
		return;
	}
	Node* pCur2 = NULL;
	pCur2 = pCur->getPdown();
	while (pCur2->getPdown())
		pCur2 = pCur2->getPdown(); //go to last name node under the department node
	while (pCur2->getPup() != pCur)
	{//moving node
		cout << pCur->getDname() << "/"; //print department
		cout << pCur2->getname()<<"/";//name
		cout << pCur2->getG()->getGrade() << "/";//grade
		cout << pCur2->getS()->getStudentID() << "/";//id
		cout << pCur2->getC()->getContact() << endl;//contact
		//print file
		fout << pCur->getDname() << "/";
		fout << pCur2->getname() << "/";
		fout << pCur2->getG()->getGrade() << "/";
		fout << pCur2->getS()->getStudentID() << "/";
		fout << pCur2->getC()->getContact() << endl;
		pCur2 = pCur2->getPup(); //go to up node
	}
	//print last name node
	cout << pCur->getDname() << "/";
	cout << pCur2->getname() << "/";
	cout << pCur2->getG()->getGrade() << "/";
	cout << pCur2->getS()->getStudentID() << "/";
	cout << pCur2->getC()->getContact() << endl;
	fout << pCur->getDname() << "/";
	fout << pCur2->getname() << "/";
	fout << pCur2->getG()->getGrade() << "/";
	fout << pCur2->getS()->getStudentID() << "/";
	fout << pCur2->getC()->getContact() << endl;
	cout << endl;
	fout << endl;
	fout.close(); //file close
}

void Manager::PRINT_STUDENT_ID()
{//print all of data using insertion sort by student id
	ofstream fout;
	fout.open("Log.txt", ios::app); //file open
	if (N_list == NULL)
	{
		cout << "Error code - 700" << endl;
		fout << "Error code - 700" << endl;
		fout.close();
		return;
	}
	NameList *newList = new NameList(); //make new link using name list
	StudentIDNode *pCur = S_list->getS_head();
	while (pCur)
	{//set new list using all of student id
		Node *node = new NameNode; 
		node->setname(pCur->getStudentID());
		node->setPnext(newList->getN_head());
		if(newList->getN_head() != NULL)
			newList->getN_head()->setPprev(node);
		newList->setN_head(node);
		pCur = pCur->getPfront();
	}
	Node *ppCur = NULL; //current
	Node *nCur = NULL; //pointer using next node
	Node *pppCur = NULL; //walker
	for (ppCur = newList->getN_head()->getPnext(); ppCur;)
	{//moving current from 1 to last
		bool located = false; //located value using bool type
		char temp[30]; //temp store data
		strcpy_s(temp, ppCur->getname()); 
		for (pppCur = ppCur->getPprev(); pppCur && !located;)
		{//moving walker from current-1 to 1
			if (strcmp(temp, pppCur->getname()) < 0)
			{//if need to change data
				pppCur->getPnext()->setname(pppCur->getname());
				if (pppCur->getPprev() != NULL)
				{//moving next pointer
					pppCur = pppCur->getPprev();
				}
				else
					pppCur = NULL;
			}
			else
				located = true; //make true
		}
		if (pppCur == NULL)//if first node should change
			newList->getN_head()->setname(temp);
		else//else
			pppCur->getPnext()->setname(temp);
		//moving next pointer
		if (ppCur->getPnext() != NULL)
			ppCur = ppCur->getPnext();
		else
			ppCur = NULL;
	}
	ppCur = newList->getN_head(); //get head of new list
	Node* D = NULL;
	while (ppCur)
	{
		//find name node in old Namelist using sorted student id
		pppCur = N_list->findNameNodeusingID(ppCur->getname());
		D = pppCur->getPup(); //find Department node of name node
		while (D->getPup())
			D = D->getPup();
		
		cout << D->getDname() << "/"; //print department
		cout << pppCur->getname() << "/"; //name
		cout << pppCur->getG()->getGrade() << "/";//grade
		cout << pppCur->getS()->getStudentID() << "/"; //id
		cout << pppCur->getC()->getContact() << endl; //contact
		//print in file
		fout << D->getDname() << "/";
		fout << pppCur->getname() << "/";
		fout << pppCur->getG()->getGrade() << "/";
		fout << pppCur->getS()->getStudentID() << "/";
		fout << pppCur->getC()->getContact() << endl;
		//delete memory
		delete ppCur->getC();
		delete ppCur->getS();
		delete ppCur->getG();
		ppCur = ppCur->getPnext(); //next node
	}
	delete newList; //delete newList
	cout << endl;
	fout << endl;
	fout.close();//file close
}

void Manager::PRINT_CONTACT()
{//print all of data using selection sort by contact
	ofstream fout;
	fout.open("Log.txt", ios::app); //file open
	if (N_list == NULL)
	{
		cout << "Error code - 800" << endl;
		fout << "Error code - 800" << endl;
		fout.close();
		return;
	}
	NameList *newList = new NameList(); //make new link using name list
	ContactNode* pCur = C_list->getC_head();
	while (pCur)
	{//set new list using all of contact
		Node *node = new NameNode;
		node->setname(pCur->getContact());
		node->setPnext(newList->getN_head());
		if (newList->getN_head() != NULL)
			newList->getN_head()->setPprev(node);
		newList->setN_head(node);
		pCur = pCur->getPright();
	}
	char temp[50]; //temp
	Node *ppCur = NULL;   //current
	Node *nCur = NULL; //smallest
	Node *pppCur = NULL; //walker
	for (ppCur = newList->getN_head(); ppCur->getPnext();ppCur = ppCur->getPnext())
	{//moving current from 0 to last-1
		nCur = ppCur; //smallest = current
		for (pppCur = ppCur->getPnext(); pppCur; pppCur = pppCur->getPnext())
		{//moving walker from current+1 to last
			if (strcmp(pppCur->getname(), nCur->getname()) > 0)
				nCur = pppCur; //if list[walker] < list[smallest]->smallest = walker
		}
		//swap
		strcpy_s(temp, ppCur->getname());
		ppCur->setname(nCur->getname());
		nCur->setname(temp);
	}


	ppCur = newList->getN_head(); //get head of new list
	Node* D = NULL;
	while (ppCur)
	{
		//find name node in old Namelist using sorted contact
		pppCur = N_list->findNameNodeusingContact(ppCur->getname());
		D = pppCur->getPup(); //find Department node of name node
		while (D->getPup())
			D = D->getPup();

		cout << D->getDname() << "/"; //print department
		cout << pppCur->getname() << "/";//name
		cout << pppCur->getG()->getGrade() << "/";//grade
		cout << pppCur->getS()->getStudentID() << "/";//id
		cout << pppCur->getC()->getContact() << endl;//contact
		//print in file
		fout << D->getDname() << "/";
		fout << pppCur->getname() << "/";
		fout << pppCur->getG()->getGrade() << "/";
		fout << pppCur->getS()->getStudentID() << "/";
		fout << pppCur->getC()->getContact() << endl;
		delete ppCur->getC();
		delete ppCur->getS();
		delete ppCur->getG(); //delete memory
		ppCur = ppCur->getPnext();//move next

	}
	delete newList; //delete newlist
	cout << endl;
	fout << endl;
	fout.close();//file close

}

bool Manager::FIND_NAME(char * name)
{//find name using first name or full name
	int flag = 0;
	ofstream fout;
	fout.open("Log.txt", ios::app); //file open
	Node* D = NULL;
	if (strlen(name) == 6 || strlen(name) == 4)
	{//if find name node using full name
		Node* pCur = N_list->getN_head();
		if (pCur == NULL)
		{//if can not found
			fout.close(); //file close
			return false;
		}
		while (pCur)
		{
			if (!strcmp(pCur->getname(), name))
			{//print data of name node 
				D = pCur->getPup(); //find Department node of name node
				while (D->getPup())
					D = D->getPup();
				cout << D->getDname() << "/"; //print department
				cout << pCur->getname() << "/";//name
				cout << pCur->getG()->getGrade() << "/";//grade
				cout << pCur->getS()->getStudentID() << "/";//id
				cout << pCur->getC()->getContact() << endl;//contact
				//print in file
				fout << D->getDname() << "/";
				fout << pCur->getname() << "/";
				fout << pCur->getG()->getGrade() << "/";
				fout << pCur->getS()->getStudentID() << "/";
				fout << pCur->getC()->getContact() << endl;
				flag++;
			}
			pCur = pCur->getPnext();
		}
	}
	else
	{//if find name node using first name using bubble sort
		Node* pCur = N_list->getN_head();
		NameList* newList = new NameList; //make new list

		while (pCur)
		{//make new name linked list had same first name
			char fn[100];
			strcpy_s(fn, pCur->getname());
			fn[2] = '\0'; //make first name
			if (!strcmp(fn, name))
			{//insert name node had same first name
				newList->insertNameNode(pCur->getname(),pCur->getG()->getGrade(),
					pCur->getS()->getStudentID(),pCur->getC()->getContact());
			}
			pCur = pCur->getPnext();
		}
		Node* ppCur = NULL; //current
		//pCur is walker
		for (ppCur = newList->getN_head(); ppCur; ppCur = ppCur->getPnext())
		{//moving current from 0 to last-1
			for (pCur = ppCur; pCur; pCur = pCur->getPnext())
			{//moving walker from last to current+1
				if (strcmp(ppCur->getname(), pCur->getname()) > 0)
				{//if need to change, change data
					char tn[20], ts[20], tc[20], tg;
					//swap
					strcpy_s(tn, ppCur->getname());
					strcpy_s(ts, ppCur->getS()->getStudentID());
					strcpy_s(tc, ppCur->getC()->getContact());
					tg = ppCur->getG()->getGrade();
					ppCur->setname(pCur->getname());
					ppCur->setC(pCur->getC());
					ppCur->setS(pCur->getS());
					ppCur->setG(pCur->getG());
					pCur->setname(tn);
					pCur->getS()->setStudentID(ts);
					pCur->getC()->setContact(tc);
					pCur->getG()->setGrade(tg);
				}
			}
		}
		pCur = newList->getN_head(); //get head of new list
		while (pCur)
		{
			//find name node using name, id, contact
			ppCur = N_list->findNameNode(pCur->getname(), pCur->getS()->getStudentID()
				, pCur->getC()->getContact());
			D = ppCur->getPup(); //find Department node of name node
			while (D->getPup())
				D = D->getPup();
			cout << D->getDname() << "/"; //print department
			cout << pCur->getname() << "/";//name
			cout << pCur->getG()->getGrade() << "/";//grade
			cout << pCur->getS()->getStudentID() << "/";//id
			cout << pCur->getC()->getContact() << endl;//contact
			//print in file
			fout << D->getDname() << "/";
			fout << pCur->getname() << "/";
			fout << pCur->getG()->getGrade() << "/";
			fout << pCur->getS()->getStudentID() << "/";
			fout << pCur->getC()->getContact() << endl; 
			delete pCur->getC();
			delete pCur->getS();
			delete pCur->getG();//delete memory
			pCur = pCur->getPnext();//next
			flag++;
		}
		delete newList;//delte new list
	}
	fout.close();//file close
	if (flag == 0)
	{
		return false;
	}
	return true;
}

bool Manager::SAVE(char * filename)
{//SAVE function
	if (filename == NULL)
		return false; //if file name is NULL;
	ofstream fout;
	fout.open(filename); //make and open file
	Node* pCur = D_list->getD_head();
	Node* name = NULL;
	while (1)
	{
		name = pCur->getPdown(); //get name node under the department
		while (name)
		{
			fout << pCur->getDname() << "/";
			fout << name->getname()<<"/";
			fout << name->getG()->getGrade() << "/";
			fout << name->getS()->getStudentID() << "/";
			fout << name->getC()->getContact() << endl;
			name = name->getPdown();
		}
		pCur = pCur->getPnext();
		if (pCur == D_list->getD_head())
			break;
	}
	fout << endl;
	fout.close(); //file close
	return true;
}
