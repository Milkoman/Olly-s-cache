#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.hpp"
#include "ListNode.hpp"

class EmptyList {};

template<typename T>
class Queue : protected LinkedList<T>
{
public:
	//Default Constructor
	Queue() {};
	//Destructor
	~Queue() { this->clear(); };
	bool isEmpty() { return this->getCount() == 0; };
	void enqueue(const T &);
	T dequeue();
	T queueFront();
	T queueRear();
	void empty() { this->clear(); }
	int getSize() { return this->getCount(); }
};





/************************************************************************
	Pre:
	Perameters: data (const T&)
	Post: a new node with given data is inserted at the end of the line
*************************************************************************/
template<typename T>
inline void Queue<T>::enqueue(const T & data)
{
	ListNode<T> *newNode = new ListNode<T>(data);
	if (this->getCount() == 0) {
		
		newNode->setNext(nullptr);
		this->setTail(newNode);
		this->setHead(newNode);
	}
	else {
		this->getTail()->setNext(newNode);
		this->setTail(newNode);
	}
	this->setCount(this->getCount() + 1);
}


/************************************************************************
	Pre: Queue is not empty
	Perameters:
	Post: first item in line is removed from line and returned to caller
*************************************************************************/
template<typename T>
inline T Queue<T>::dequeue()
{
	if (this->getCount() > 0)
	{
		T data = this->getData(1);
		this->remove(1);
		return data;
	}
	else
	{
		throw EmptyList();
	}
}

/***********************************************************
	Pre: Queue is not empty
	Perameters:
	Post: returns data from the first node in line to caller
************************************************************/
template<typename T>
inline T Queue<T>::queueFront()
{
	if (this->getCount() > 0)
	{
		return this->getHead()->getData();
	}
	else {
		throw EmptyList();
	}
}

/***********************************************************
	Pre: Queue is not empty
	Perameters:
	Post: returns data from the last node in line to caller
************************************************************/
template<typename T>
inline T Queue<T>::queueRear()
{
	if (this->getCount() > 0)
	{
		return this->getTail()->getData();
	}
	else {
		throw EmptyList();
	}
}
#endif // !QUEUE_H