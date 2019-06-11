#ifndef FOODPROCESSOR_H
#define FOODPROCESSOR_H
#include "BinaryTree.hpp"
#include "Food.hpp"

class FoodProcessor
{
private:
	BinaryTree<Food> calTree;
	BinaryTree<Food> fatTree;
	BinaryTree<Food> carbTree;
	BinaryTree<Food> protTree;
	
public:
	FoodProcessor();
	~FoodProcessor();

	void add(const Food &);

	
};

#endif // !FOODPROCESSOR_H
