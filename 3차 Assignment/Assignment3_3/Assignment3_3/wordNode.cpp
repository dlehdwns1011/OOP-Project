#include "wordNode.h"
#include <iostream>
#include <cstring>

using namespace std;

wordNode::wordNode()
{
	*word = 0;
	wNext = NULL;
}

wordNode::~wordNode()
{
}
