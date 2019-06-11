#include<iostream>
#include<fstream>
#include <functional>
#include "Food.hpp"
#include "BinaryTree.hpp"

using namespace std;

//void (Queue<Food>::*pt2Member)(const Food &) = NULL;

typedef void(Queue<Food>::*TArg)(const Food &);

template <class T>
Queue<T> *unloader;

template <class T>
void add(T & data) {
	unloader<T>->enqueue(data);
}

int main()
{
	fstream file;
	file.open("foodData.txt");
	Food item;

	//pt2Member = &Queue<Food>::enqueue;

	TArg pTArg = &Queue<Food>::enqueue;

	BinaryTree<Food> calTree;
	Queue<Food> testQ;
	unloader<Food> = &testQ;
	while (file >> item)
	{
		cout << item << endl;
		calTree.add(item, Food::calorieLGreaterR);
		calTree.inorderTraverse(add);
	}

	cout << "BTREE\n";
	cout << calTree;
	cout << "\n\n\n\n" << testQ.dequeue();

	cout << "\n\nTEST!\n\n";
	system("pause");
	return 0;
}