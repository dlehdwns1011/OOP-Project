#pragma once

#include <iostream>

using std::ostream;

namespace kw

{

	template<typename T>

	class Node
	{
	public:
		T               mData; //data in node
		Node<T>*	mNextNode; //pointer to next node

		Node(const T& data)	:mData(data),mNextNode(NULL)
		{//insert only data in node
			mData = data;
			mNextNode = NULL;
		}
		Node(const T& data, Node<T>* nextNode):mData(data),mNextNode(nextNode)
		{//insert data, next node in node
			mData = data;
			mNextNode = nextNode;
		}
		Node():mData(NULL),mNextNode(NULL)
		{//just initiailize node
			mData = NULL;
			mNextNode = NULL;
		}

	};

	template <typename T>
	class LinkedList
	{
	private:
		Node<T>*                mHead; //Head node
		unsigned int		mSize; //size of linked List

	public:
		LinkedList() { mHead = NULL; mSize = 0; }
		~LinkedList() { clear(); }
		virtual T                       get(const int index) const
		{//get Node in index
			Node<T>* pCur = mHead; //get head node
			int i;
			for (i = 0; i < mSize; i++)
			{//find n index node
				if (i == index)
					break;
				pCur = pCur->mNextNode;
			}
			if (i == mSize)
				return NULL; //if cant find
			else
				return pCur->mData;//if can find
		}

		virtual bool			set(const int index, const T& data)
		{//set Node in index - change data
			if (index > mSize)
				return false; //if not exist index node
			Node<T>* pCur = mHead;
			for (int i = 0; i < index; i++)
				pCur = pCur->mNextNode; //find index node
			pCur->mData = data; //change data
			return true;
		}



		virtual bool			insert(const T& data)
		{//insert node in tail of linked List
			if (mHead == NULL)
			{//empty Head - first insert
				insertHead(data); //call insertHead
				return true;
			}
			Node<T>* pNode = new Node<T>(data); //make node had data
			Node<T>* pCur = mHead; //get head node
			while (pCur->mNextNode)
				pCur = pCur->mNextNode; //find last node in linked List
			pCur->mNextNode = pNode; //new linked
			mSize++; //size + 1
			return true;

		}

		virtual bool			insert(const int index, const T& data)
		{//insert node in index position of linked List
			if (index > mSize)
				return false; //if can't insert in index
			Node<T>* pCur = mHead; //get head node
			if (index == 0)
			{//if insert node in head
				insertHead(data);
				return true;
			}
			for (int i = 0; i < index - 1; i++)
				pCur = pCur->mNextNode; //find before node of will insert node

			Node<T>* pNode = new Node<T>(data,pCur->mNextNode);
			//make node had data, next node of before node 
			pCur->mNextNode = pNode; //new linked
			mSize++; //size + 1
			return true;
		}



		virtual bool			insertHead(const T& data)
		{//insert node in head
			Node<T>* pNode = new Node<T>(data);
			if (mHead == NULL)
			{//empty Head - first insert
				mHead = pNode;
				mSize++;
				return true;
			}
			pNode->mNextNode = mHead; 
			mHead = pNode; //set new head
			mSize++; //size + 1
			return true;
		}



		virtual bool			pop()
		{//delete last node in linked List
			if (empty() == true)
				return false; //if not exist linked List
			Node<T>* pCur = mHead; //get head node
			Node<T>* ppCur = NULL; 
			while (pCur->mNextNode)
			{//find last node
				ppCur = pCur; //it is before node of last node
				pCur = pCur->mNextNode;
			}
			ppCur->mNextNode = NULL; //new linked
			delete pCur; //delete last node
			mSize--; //size - 1
			return true;
		}

		virtual bool			pop(const int index)
		{//delete index node in linked List
			if (index > mSize)
				return false; //if want delete not exist node
			if (empty() == true)
				return false; //if not exist linked List 
			Node<T>* pCur = mHead; //get head node
			Node<T>* ppCur = NULL;
			for (int i = 0; i < mSize; i++)
			{//find index node in linked List
				if (i == index)
					break;
				ppCur = pCur; //it is before node of index node
				pCur = pCur->mNextNode;
			}
			if (index == 0) //if want delete head node
				mHead = mHead->mNextNode; //set new head
			else//else
				ppCur->mNextNode = pCur->mNextNode;
			mSize--; //size - 1
			delete pCur; //delete node
			return true;
		}



		virtual unsigned int            size()	const
		{//get size of linked List
			return mSize;
		}

		virtual bool			empty() const
		{//check linked List is empty or not
			if (mSize == 0) //if empty, return true
				return true;
			else
				return false;
		}



		virtual void			clear()
		{//delete all of node in linked List
			Node<T>* pCur = mHead; //get head node
			Node<T>* ppCur = NULL;
			while (pCur)
			{//delete node by moving node
				ppCur = pCur;
				pCur = pCur->mNextNode;
				delete ppCur;
			}
			mSize = 0; //reset size
			mHead = NULL; //reset head
		}



		friend ostream& operator<<(ostream& os, const LinkedList<T>& data)
		{//print all of node in linked List
			if (data.mHead == NULL)
			{//if empty
				os << "This linked list is empty." << endl;
			}
			else
			{
				os << "------------------------------------" << endl;
				for (int i = 0; i < data.size(); i++) //moving node
				{//print data of node
					os << "idx: " << i<<" , data: ";
					os << data.get(i)<<endl;
				}
				os << "------------------------------------" << endl;
			}

			return os;
		}
	};
}