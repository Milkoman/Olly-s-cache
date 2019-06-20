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
void printIndent(T & data, int h) {
	for (int i = 1; i < h; i ++) {
		cout << '\t';
	}
	cout << data << '\n';
}

template <class T>
Queue<T> qT;

int main()
{
	fstream file;
	file.open("foodData.txt");
	
	FoodProcessor fp;
	Queue<Food> testQ;
	Food item;

	BinaryTree<Food> calTree;
	BinaryTree<Food> newTree;
	while (file >> item)
	{
		Food * newItem = new Food(item);
		calTree.add(*newItem, Food::calorieLGreaterR);
		fp.add(*newItem);
	}
	cout << "BTREE\n";
	//cout << calTree;

	cout << calTree;
	cout << "\n\n\n";
	cout << fp.getNumFoods() << "\n\n";


	calTree.inorderTraverse(printIndent);
	Food del("apple",95,0,25,1);
	calTree.remove(del,Food::completeLEqualR, Food::calorieLGreaterR);
	cout << "\n\n\n\n";
	calTree.inorderTraverse(printIndent);
	//fp.calIntersectTraverse(ADTStatic::loadBinaryTree, newTree, 0, 50, 0, 50, 0, 4, 0, 50);
	//newTree.inorderTraverse(print);



	cout << "\n\nTEST!\n\n";
	system("pause");
	return 0;
}