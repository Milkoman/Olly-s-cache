#include "Food.hpp"

Food::Food()
{
}

Food::Food(const string n, const int cal, const int f, const int c, const int p) : name(n), calorie(cal), fat(f), carb(c), protien(p)
{
}

bool Food::operator>(const Food &right)
{
	return name > right.name;
}

bool Food::calorieLGreaterR(const Food & left, const Food & right)
{
	return left.calorie > right.calorie;
}

bool Food::fatLGreaterR(const Food & left, const Food & right)
{
	return left.fat > right.fat;
}

bool Food::carbLGreaterR(const Food & left, const Food & right)
{
	return left.carb > right.carb;
}

bool Food::proteinLGreaterR(const Food & left, const Food & right)
{
	return left.protien > right.protien;
}

bool Food::calorieLLessR(const Food & left, const Food & right)
{
	return left.calorie < right.calorie;
}
bool Food::fatLLessR(const Food & left, const Food & right)
{
	return left.fat < right.fat;
}
bool Food::carbLLessR(const Food & left, const Food & right)
{
	return left.carb < right.carb;
}
bool Food::proteinLLessR(const Food & left, const Food & right)
{
	return left.protien < right.protien;
}

ostream & operator<<(ostream &strm, const Food &obj)
{
	strm << obj.name << " " << obj.calorie << " " << obj.fat << " " << obj.carb << " " << obj.protien;
	return strm;
}

istream & operator>>(istream &strm, Food &obj)
{
	//std::cout << "Enter item name: ";
	getline(strm, obj.name, '\n');
	//std::cout << "Enter cal. fat. carb. prot.: ";
	strm >> obj.calorie >> obj.fat >> obj.carb >> obj.protien;
	strm.ignore(20, '\n');
	return strm;
}
