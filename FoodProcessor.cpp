#include "FoodProcessor.hpp"

FoodProcessor::FoodProcessor()
{
}

FoodProcessor::~FoodProcessor()
{
}

void FoodProcessor::add(const Food &food)
{
	calTree.add(food, Food::calorieLGreaterR);
	fatTree.add(food, Food::fatLGreaterR);
	carbTree.add(food, Food::carbLGreaterR);
	protTree.add(food, Food::proteinLGreaterR);
}
