
#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

using std::ostream;
template <class T>
class ListNode;
template <class T>
ostream &operator<< (ostream &, const ListNode<T> &);



//******************************************
// This ListNode class creates a type used
// to store a node in the LinkedList class.
//******************************************

template <class Type>
class ListNode
{
private:
	Type data;              //Node Value
	ListNode<Type> *next;   //Pointer to next node
public:
	//Constructors
	ListNode();
	ListNode(const Type &);
	ListNode(const Type &, ListNode<Type> *);
	//Setters
	void setData(const Type &nodeData) { data = nodeData; }
	void setNext(ListNode<Type>* nextPtr) { next = nextPtr; }
	//Getters
	Type getData() const { return data; }
	ListNode<Type> * getNext() const { return next; }

	template <class T>
	friend ostream &operator<< (ostream &, const ListNode<T> &);


};

/*****************************************************************
	Pre:
	Perameters:
	Post: Sets next pointer to null, doesn't initialize data
******************************************************************/
template<class Type>
inline ListNode<Type>::ListNode() : next(nullptr)
{
} //end default constructor

/******************************************************************
	Pre:
	Perameters: nodeData(const Type&)
	Post: Sets next pointer to null, initializes data to nodeData
*******************************************************************/
template<class Type>
inline ListNode<Type>::ListNode(const Type & nodeData) : data(nodeData), next(nullptr)
{
}

/**************************************************************************
	Pre:
	Perameters: nodeData(const Type&), nextPtr(ListNode<Type> *)
	Post: Initializes next pointer to nextPtr, initializes data to nodeData
****************************************************************************/
template<class Type>
inline ListNode<Type>::ListNode(const Type & nodeData, ListNode<Type>* nextPtr) : data(nodeData), next(nextPtr)
{
};

/**************************************************************************
	Pre:
	Perameters: ostream & strm, ListNode<T> & obj
	Post: outputs the data of the node to the ostream, and returns the ostream
****************************************************************************/
template<class T>
inline ostream & operator<<(ostream &strm, const ListNode<T> &obj)
{
	strm << obj.getData();
	return strm;
}
#endif
