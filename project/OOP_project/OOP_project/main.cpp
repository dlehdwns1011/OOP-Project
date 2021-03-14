#include <iostream>
#include "Manager.h"
#include <crtdbg.h>

using namespace std;

int main()
{//start main
	Manager k; //manager object
	k.ReadCommand("Command.txt");//start readcommand function
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |  _CRTDBG_LEAK_CHECK_DF);

	return 0;//end main
}