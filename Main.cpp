 #include<iostream>
#include<fstream>
#include "Food.hpp"
#include "BinaryTree.hpp"
#include "Queue.hpp"
#include "FoodProcessor.hpp"
#include "ADTStatic.hpp"

using namespace std;


template <class T>
void add(Queue<T> & queue, T & data){
	queue.enqueue(data);
}

template <class T>
void add(BinaryTree<T> & btree, T & data)
{
	btree.add(data);
}

template <class T>
void add(BinaryTree<T> & btree, T & data, bool LGR(const T &, const T &))
{
	btree.add(data, LGR);
}

template <class T>
void print(T & data) {
	cout << data;
}

template <class T>
Queue<T> qT;

int main()
{
	fstream file;
	file.open("foodData.txt");
	Food item;
	FoodProcessor fp;
	Queue<Food> testQ;

	BinaryTree<Food> calTree;
	BinaryTree<Food> newTree;
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


	//fp.calRangeTraverse(print, 0, 50);

	fp.calIntersectTraverse(ADTStatic::loadBinaryTree, newTree, 0, 50, 0, 50, 0, 4, 0, 50);
	newTree.inorderTraverse(print);



	cout << "\n\nTEST!\n\n";
	system("pause");
	return 0;
}