// Chapter04.cpp -- Programming exercises for Chapter 04
#include <iostream>
#include <string>
#include <cstring>
#include <array>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;

// Programming Exercises 4.1
void displayInformation() {
	const int ArrSize = 20;
	char firstName[ArrSize], lastName[ArrSize], letter;
	int age;

	// Because a number was enteredin the main function, when cin reads the number,
	// it leaves the newline generated by the Enter key in the input queue. Then,
	// cin.getline() reads the newline as an empty line and assigns a null string to
	// the first name. cin.get() function solves this problem.
	// cin.get();	It was added in the main, which can solve the issue in each function.
	cout << "What is your first name? ";
	cin.getline(firstName, ArrSize);
	cout << "What is your last name? ";
	cin.getline(lastName, ArrSize);
	cout << "What letter grade do you deserve? (A or B or C) ";
	cin >> letter;
	cout << "What is your age? ";
	(cin >> age).get();

	cout << "Name: " << lastName << ", " << firstName << endl;
	cout << "Grade: " << char(letter + 1) << endl;
	cout << "Age: " << age << endl;
}

// Programming Exercises 4.2
void instr2() {
	string name, dessert;

	cout << "Enter your name:\n";
	getline(cin, name);	// getline is a great function to remember for string.
	cout << "Enter your favorite dessert:\n";
	getline(cin, dessert);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
}

// Programming Exercises 4.3
void nameInArray() {
	const int ArrSize = 20;
	char firstName[ArrSize], lastName[ArrSize];

	cout << "Enter your first name: ";
	cin.getline(firstName, ArrSize);
	cout << "Enter your last name: ";
	cin.getline(lastName, ArrSize);

	char fullname[ArrSize + ArrSize] = {'\0'};
	// To let strcat function works in Microsoft Visual Studio 2017,
	// Project -> Properties -> Configuration Properties -> C/C++ -> Preprocessor
	// -> Preprocessor Definitions -> <Edit...> -> Add "_CRT_SECURE_NO_WARNINGS"
	strcat(strcat(strcat(fullname, firstName), ", "), lastName);
	cout << "Here's the information in a single string: " << fullname << endl;
}

// Programming Exercises 4.4
void nameInString() {
	string firstName, lastName;

	cout << "Enter your first name: ";
	getline(cin, firstName);
	cout << "Enter your last name: ";
	getline(cin, lastName);
	cout << "Here's the information in a single string: "
		<< firstName + ", " + lastName << endl;
}

// Programming Exercises 4.5
void candyBarStruct() {
	struct CandyBar {
		char brandName[20];
		double weight;
		int calories;
	};

	CandyBar snack {"Mocha Munch", 2.3, 350};
	cout << "The cany bar's brand name is " << snack.brandName
		<< ".\nIt is " << snack.weight << " pounds.\nAnd, it has "
		<< snack.calories << " calories." << endl;
}

// Programming Exercises 4.6
void candyBarArray() {
	struct CandyBar {
		char brandName[20];
		double weight;
		int calories;
	};

	CandyBar candyBar[3];
	candyBar[0] = { "Hershey", 2.3, 350 };
	candyBar[1] = { "Lindt", 1.8, 220 };
	candyBar[2] = { "Mars", 3.5, 410 };

	cout << "The candy bar's brand name is " << candyBar[0].brandName
		<< ".\nIt is " << candyBar[0].weight << " pounds.\nAnd, it has "
		<< candyBar[0].calories << " calories.\n" << endl;

	cout << "The candy bar's brand name is " << candyBar[1].brandName
		<< ".\nIt is " << candyBar[1].weight << " pounds.\nAnd, it has "
		<< candyBar[1].calories << " calories.\n" << endl;

	cout << "The candy bar's brand name is " << candyBar[2].brandName
		<< ".\nIt is " << candyBar[2].weight << " pounds.\nAnd, it has "
		<< candyBar[2].calories << " calories." << endl;
}

// Programming Exercise 4.7
void pizzaAnalysis() {
	struct Pizza {
		string name;
		double diameter;
		double weight;
	};

	Pizza onePizza;
	cout << "Please create a pizza:\n";
	cout << "Enter the name of the pizza: ";
	getline(cin, onePizza.name);
	cout << "Enter the diameter of the pizza (inch): ";
	cin >> onePizza.diameter;
	cout << "Enter the weight of the pizza (pound): ";
	cin >> onePizza.weight;

	cout << "The pizza's name is " << onePizza.name
		<< ". Its diameter is " << onePizza.diameter << " inches and weight is "
		<< onePizza.weight << " pounds." << endl;
}

// Programming Exercise 4.8
void pizzaAnalysisPointer() {
	struct Pizza {
		string name;
		double diameter;
		double weight;
	};

	Pizza* ptrOnePizza = new Pizza;
	cout << "Please create a pizza:\n";
	cout << "Enter the name of the pizza: ";
	getline(cin, (*ptrOnePizza).name);
	cout << "Enter the diameter of the pizza (inch): ";
	cin >> (*ptrOnePizza).diameter;
	cout << "Enter the weight of the pizza (pound): ";
	cin >> (*ptrOnePizza).weight;

	cout << "The pizza's name is " << (*ptrOnePizza).name
		<< ". Its diameter is " << (*ptrOnePizza).diameter << " inches and weight is "
		<< (*ptrOnePizza).weight << " pounds." << endl;
	delete ptrOnePizza;
}

// Programming Exercises 4.9
void candyBarArrayPointer() {
	struct CandyBar {
		char brandName[20];
		double weight;
		int calories;
	};

	CandyBar* ptrCandyBar = new CandyBar[3];
	ptrCandyBar[0] = { "Hershey", 2.3, 350 };
	ptrCandyBar[1] = { "Lindt", 1.8, 220 };
	ptrCandyBar[2] = { "Mars", 3.5, 410 };

	cout << "The candy bar's brand name is " << ptrCandyBar[0].brandName
		<< ".\nIt is " << ptrCandyBar[0].weight << " pounds.\nAnd, it has "
		<< ptrCandyBar[0].calories << " calories.\n" << endl;

	cout << "The candy bar's brand name is " << ptrCandyBar[1].brandName
		<< ".\nIt is " << ptrCandyBar[1].weight << " pounds.\nAnd, it has "
		<< ptrCandyBar[1].calories << " calories.\n" << endl;

	cout << "The candy bar's brand name is " << ptrCandyBar[2].brandName
		<< ".\nIt is " << ptrCandyBar[2].weight << " pounds.\nAnd, it has "
		<< ptrCandyBar[2].calories << " calories." << endl;
	delete[] ptrCandyBar;
}

// Programming Exercises 4.10
void averageTime() {
	std::array<double, 3> dash;
	double average;

	cout << "Enter the 1st time for the 40-yd dash: ";
	cin >> dash[0];
	cout << "Enter the 2nd time for the 40-yd dash: ";
	cin >> dash[1];
	cout << "Enter the 3rd time for the 40-yd dash: ";
	cin >> dash[2];

	average = (dash[0] + dash[1] + dash[2]) / 3.0;
	cout << "\nThe 1st time is " << dash[0] << "s.";
	cout << "\nThe 2nd time is " << dash[1] << "s.";
	cout << "\nThe 3rd time is " << dash[2] << "s.";
	cout << "\nThe average time is " << average << "s.\n";
}

int main() {
	int exerciseNum;
	cout << "Which exercise do you want to test? (1-10) (Enter \"0\" to quit)\n";
	(cin >> exerciseNum).get();

	while (exerciseNum < 0) {
		cout << "Please provide a valid number!" << endl;
		cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << endl;
		cout << "Which exercise do you want to test? (1-10) (Enter \"0\" to quit)\n";
		(cin >> exerciseNum).get();
	}

	while (exerciseNum != 0) {
		switch (exerciseNum) {
		case 1: // Test Programming Exercise 4.1
			displayInformation();
			break;
		case 2:	// Test Programming Exercise 4.2
			instr2();
			break;
		case 3:	// Test Programming Exercise 4.3
			nameInArray();
			break;
		case 4:	// Test Programming Exercise 4.4
			nameInString();
			break;
		case 5:	// Test Programming Exercise 4.5
			candyBarStruct();
			break;
		case 6:	// Test Programming Exercise 4.6
			candyBarArray();
			break;
		case 7:	// Test Programming Exercise 4.7
			pizzaAnalysis();
			break;
		case 8:	// Test Programming Exercise 4.8
			pizzaAnalysisPointer();
			break;
		case 9:	// Test Programming Exercise 4.9
			candyBarArrayPointer();
			break;
		case 10:	// Test Programming Exercise 4.10
			averageTime();
			break;
		default:
			cout << "Please provide a valid number!" << endl;
			break;
		}

		cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n" << endl;
		cout << "What else do you want to test? (1-10)\n";
		(cin >> exerciseNum).get();
	}

	return 0;
}