#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main()
//start main
{



	kw::LinkedList<int> linkedList; //declare object.



	cout << "Initialization" << endl << endl;



	cout << "insertion (1)" << endl << endl;

	cout << "insertion (3)" << endl << endl;

	cout << "insertion (4)" << endl << endl;

	cout << "insertion (6)" << endl << endl;


	//insert data function
	linkedList.insert(1);

	linkedList.insert(3);

	linkedList.insert(4);

	linkedList.insert(6);



	cout << "Size of linked list = " << linkedList.size() << endl;
	//print all of node function
	cout << linkedList << endl;



	cout << "Test insertion" << endl << endl;

	cout << "insertion (1, 2)" << endl << endl;

	cout << "insertion (4, 5)" << endl << endl;


	//insert data in index node function
	linkedList.insert(1, 2);

	linkedList.insert(4, 5);



	cout << "Size of linked list = " << linkedList.size() << endl;
	//print all of node function
	cout << linkedList << endl;



	cout << "Test pop" << endl << endl;

	cout << "pop (0)" << endl << endl;

	cout << "pop (3)" << endl << endl;

	cout << "pop ()" << endl << endl;


	//pop of n index node function
	linkedList.pop(0);

	linkedList.pop(3);
	//pop of last node function
	linkedList.pop();



	cout << "Size of linked list = " << linkedList.size() << endl;
	//print all of node function
	cout << linkedList << endl;



	cout << "Test get and set function" << endl << endl;



	cout << "linkedList.get(1)  = " << linkedList.get(1) << endl;


	//change data in n index node fucntion
	linkedList.set(1, 50);



	cout << "linkedList.set(1, 50)" << endl;

	cout << "linkedList.get(1)  = " << linkedList.get(1) << endl << endl;



	cout << "Test clear" << endl << endl;
	//clear all of node in linkedList
	linkedList.clear();



	cout << "Size of linked list  = " << linkedList.size() << endl;
	//print all of node function
	cout << linkedList << endl;



	return 0;

}