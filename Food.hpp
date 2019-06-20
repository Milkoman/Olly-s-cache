#ifndef FOOD_H
#define FOOD_H
#include <string>
#include <iostream>
using std::string;
using std::ostream;
using std::istream;

class Food;
ostream &operator<< (ostream &, const Food &);
istream &operator>> (istream &, Food &);

class Food
{
	private:
		string name;
		int calorie;
		int fat;
		int carb;
		int protien;

	public:
		Food();
		Food(const string, const int, const int, const int, const int);
		Food(const Food &);
		
		//Mutators
		void setName(const string n) { name = n; }
		void setCalorie(const int c) { calorie = c; }
		void setFat(const int f) { fat = f; }
		void setCarb(const int c) { carb = c; }
		void setProtien(const int p) { protien = p; }
		//Accessors
		string getName() const { return name; }
		int getCalorie() const { return calorie; }
		int getFat() const { return fat; }
		int getCarb() const { return carb; }
		int getProtien() const { return protien; }
		//Operators
		friend ostream &operator<< (ostream &, const Food &);
		friend istream &operator>> (istream &, Food &);
		bool operator> (const Food &);
		bool operator== (const Food&);
		//Methods

		static bool calorieLGreaterR(const Food &, const Food &);
		static bool fatLGreaterR(const Food &, const Food &);
		static bool carbLGreaterR(const Food &, const Food &);
		static bool proteinLGreaterR(const Food &, const Food &);

		static bool calorieLLessR(const Food &, const Food &);
		static bool fatLLessR(const Food &, const Food &);
		static bool proteinLLessR(const Food &, const Food &);
		static bool carbLLessR(const Food &, const Food &);

		static bool calorieLEqualR(const Food &, const Food &);
		static bool fatLEqualR(const Food &, const Food &);
		static bool proteinLEqualR(const Food &, const Food &);
		static bool carbLEqualR(const Food &, const Food &);

		static bool completeLEqualR(const Food &, const Food &);
};


#endif
