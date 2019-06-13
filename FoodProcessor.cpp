#include "FoodProcessor.hpp"

FoodProcessor::FoodProcessor()
{
}

FoodProcessor::~FoodProcessor()
{
}

bool FoodProcessor::replace(const Food& food)
{
	Food old;
	try {
		old = calTree.search(food);
	}
	catch (NotFound) {
		return false;
	}
	if (old.getCalorie() != food.getCalorie() || old.getCarb() != food.getCarb() || old.getFat() != food.getFat() || old.getProtien() != food.getProtien()) {
		remove(food);
		add(food);
	}
	return true;
}

void FoodProcessor::calRangeTraverse(void visit(Food &), int min, int max)
{
	Food minF;
	Food maxF;
	minF.setCalorie(min);
	maxF.setCalorie(max);
	calTree.inorderBoundedTraverse(visit, Food::calorieLGreaterR, minF, maxF);
}

void FoodProcessor::fatRangeTraverse(void visit(Food &), int min, int max)
{
	Food minF;
	Food maxF;
	minF.setFat(min);
	maxF.setFat(max);
	fatTree.inorderBoundedTraverse(visit, Food::fatLGreaterR, minF, maxF);
}

void FoodProcessor::carbRangeTraverse(void visit(Food &), int min, int max)
{
	Food minF;
	Food maxF;
	minF.setCarb(min);
	maxF.setCarb(max);
	carbTree.inorderBoundedTraverse(visit, Food::carbLGreaterR, minF, maxF);
}

void FoodProcessor::protRangeTraverse(void visit(Food &), int min, int max)
{
	Food minF;
	Food maxF;
	minF.setProtien(min);
	maxF.setProtien(max);
	protTree.inorderBoundedTraverse(visit, Food::proteinLGreaterR, minF, maxF);
}

void FoodProcessor::add(const Food &food)
{
	calTree.add(food, Food::calorieLGreaterR);
	fatTree.add(food, Food::fatLGreaterR);
	carbTree.add(food, Food::carbLGreaterR);
	protTree.add(food, Food::proteinLGreaterR);
}

void FoodProcessor::remove(const Food& food)
{
	calTree.remove(food);
	fatTree.remove(food);
	carbTree.remove(food);
	protTree.remove(food);
}
