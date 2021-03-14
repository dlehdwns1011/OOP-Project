#include "Manager.h"
#include <iostream>

using namespace std;

void Manager::menu()
{
	Queue* q = new Queue; //make Queue
	int s; 
	while (1)
	{
		cout << "Size : "; cin >> s;
		cout << "-------------------" << endl; //set size
		q->setSize(s);
		if (s > 0 && s < 53) //if wrong insert size
			break;
		cout << "**Size have to insert from 1 to 52**" << endl;
	}
	int m = 0;
	while (m != 4) //4 is end
	{//Menu part
		cout << endl<<"Queue Size : " << s << endl;
		cout << "1. Generate Card." << endl;
		cout << "2. Delete Card." << endl;
		cout << "3. Show all card." << endl;
		cout << "4. End" << endl;
		cout << "-------------------" << endl;
		cout << "Select menu : "; cin >> m;
		if (m <= 0 || m > 4) //wrong selection menu
		{
			cout << "wrong select menu!" << endl;
			continue;
		}
		if (m == 1) //push
			q->Push();
		else if (m == 2) //pop
			q->Pop();
		else if (m == 3) //print
			q->Print();
	}
	cout << "========= END =========" << endl;
	delete q; //delete q
}
