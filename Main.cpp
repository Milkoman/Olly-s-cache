#include<iostream>
#include<fstream>
#include "Food.hpp"
#include "BinaryTree.hpp"
#include "Queue.hpp"
#include "FoodProcessor.hpp"

using namespace std;


template <class T>
Queue<T> *unloader;

template <class T>
void add(T & data) {
	unloader<T>->enqueue(data);
}

template <class T>
void addItem(Queue<T> & queue, T & data){
	queue.enqueue(data);
}

template <class T>
void qEnq(Queue<T>& data)
{
	data.enqueue();
}

template <class T>
void print(T & data) {
	cout << data;
}

int main()
{
	fstream file;
	file.open("foodData.txt");
	Food item;
	FoodProcessor fp;
	Queue<Food> testQ;

	BinaryTree<Food> calTree;
	while (file >> item)
	{
		calTree.add(item, Food::calorieLGreaterR);
		fp.add(item);
	}
	cout << "BTREE\n";
	//cout << calTree;

	cout << calTree;
	cout << "\n\n\n";
	cout << fp.getNumFoods() << "\n\n";
	calTree.breadthFirstTraversal(print);
	//calTree.inorderTraverse(addItem<Food>, testQ);
	//cout << testQ.queueFront();

	fp.calRangeTraversal(print,50, 250);

	cout << "\n\nTEST!\n\n";
	system("pause");
	return 0;
}