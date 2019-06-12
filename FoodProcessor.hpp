#ifndef FOODPROCESSOR_H
#define FOODPROCESSOR_H
#include "BinaryTree.hpp"
#include "Food.hpp"
#include "Queue.hpp"

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

	bool replace(const Food&);
	void calRangeTraversal(void visit(Food &), int min, int max);
	void fatRangeTraversal(void visit(Food &), int min, int max);
	void carbRangeTraversal(void visit(Food &), int min, int max);
	void protRangeTraversal(void visit(Food&), int min, int max);
	int getNumFoods() { return calTree.getNumNodes(); };

	void add(const Food &);
	void remove(const Food&);

	
};

#endif // !FOODPROCESSOR_H
