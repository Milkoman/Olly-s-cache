#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.hpp"

// Exception class
class OutOfBounds {};

using std::ostream;
template <class T>
class LinkedList;
template <class T>
ostream &operator<< (ostream &, const LinkedList<T> &);


template <class Type>
class LinkedList
{
	private:
		ListNode<Type> *head;
		ListNode<Type> *tail;
		int count;
		ListNode<Type>* getNodeAt(int) const;

	public:
		LinkedList();
		~LinkedList();
		ListNode<Type>* getTail() { return tail; }
		ListNode<Type>* getHead() { return head; }
		void setHead(ListNode<Type> * nodePtr) { head = nodePtr; }
		void setTail(ListNode<Type> * nodePtr) { tail = nodePtr; }
		Type getData(int) const;
		int getCount() const { return count; }
		void setCount(int cnt) { count = cnt; }
		bool isEmpty() const { return count == 0; }
		bool insertAt(const Type &data, int);
		bool remove(int);
		void clear();
	
		template <class T>
		friend ostream &operator<< (ostream &, const LinkedList<T> &);

};

/***********************************************************
	Pre:
	Perameters:
	Post: sets the head node pointer to null, and count to 0
************************************************************/
template<class Type>
inline LinkedList<Type>::LinkedList() : head(nullptr), tail(nullptr), count(0)
{
}

/************************************************************
	Pre:
	Perameters:
	Post: deletes all nodes in the list
*************************************************************/
template<class Type>
inline LinkedList<Type>::~LinkedList()
{
	clear();
}

/***************************************************************
	Pre: position is in bounds {1, count}
	Perameters: position (int)
	Post: Returns a pointer to the node at the position;
****************************************************************/
template<class Type>
inline ListNode<Type>* LinkedList<Type>::getNodeAt(int position) const
{
		ListNode<Type> *pCur = head;
		for (int i = 1; i < position; i++)
			pCur = pCur->getNext();

		return pCur;
}

/****************************************************************************
	Pre: position is in bounds {1, count}
	Perameters: position (int)
	Post: The data of type Type in the node at the given position is returned
******************************************************************************/
template<class Type>
inline Type LinkedList<Type>::getData(int position) const
{
	bool ableToGet = (position >= 1) && (position <= count);
	if (ableToGet)
	{
		ListNode<Type> *ptr = getNodeAt(position);
		return ptr->getData();
	}
	else 
	{    //!!!!! EXCEPTION !!!!
		throw OutOfBounds();
		
	}
}

/***********************************************************************************
	Pre: position is in bounds {1, count}
	Perameters: data (Type), position (int)
	Post: A new node is created and inserted at the given position with the given data
***************************************************************************************/
template<class Type>
inline bool LinkedList<Type>::insertAt(const Type &dataIn, int position)
{
	bool ableToInsert = (position >= 1) && (position <= count + 1);
	
	if (ableToInsert)
	{
		ListNode<Type>* newNode = new ListNode<Type>(dataIn);

		if (position == 1)
		{
			newNode->setNext(head);
			head = newNode;
		}
		else
		{
			ListNode<Type>* pPre = getNodeAt(position - 1);
			newNode->setNext(pPre->getNext());
			pPre->setNext(newNode);
			if (position == (count + 1)) {
				tail = pPre->getNext();
			}
			
			
		}
		count++;
		return ableToInsert;
	}
	else
		return false;
}

/*************************************************************
	Pre: position is in bounds {1, count}
	Perameters: position (int)
	Post: The node at the given position is removed returns 
	whether the remove was successful
**************************************************************/
template<class Type>
inline bool LinkedList<Type>::remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= count);
	if (ableToRemove)
	{
		ListNode<Type>* pCur = nullptr;
		if (position == 1)
		{
			pCur = head;
			head = head->getNext();
		}
		else
		{
			ListNode<Type>* pPre = getNodeAt(position - 1);
			if (position == count) {
				tail = pPre;
			}
			pCur = pPre->getNext();
			pPre->setNext(pCur->getNext());
			
		}
		// return node to system
		pCur->setNext(nullptr);
		delete pCur;
		pCur = nullptr;
		count--;
		return ableToRemove;
	}
	else
		return false;
		

}

/**********************************************
	Pre:
	Perameters:
	Post: All nodes in the list are removed
***********************************************/
template<class Type>
inline void LinkedList<Type>::clear()
{
	while (!isEmpty())
		remove(1);
}


/**************************************************************************
	Pre:
	Perameters: ostream & strm, LinkedList<T> & obj
	Post: Outputs all of the nodes in the linked list from front to back, and returns the ostream
****************************************************************************/
template<class T>
inline ostream & operator<<(ostream &strm, const LinkedList<T> &obj)
{
	for (int i = 1; i <= obj.getCount(); i++)
	{
		strm << obj.getData(i) << "\n";
	}
	
	return strm;
}

#endif
