#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct students
{
	std::vector<std::string> name = {};
	std::vector<int> quiz = {};
	std::vector<int> act= {};
	std::vector<int> lab = {};
	std::vector<int> exam = {};
};

std::string inputStr(std::string prompt)
{
	std::string input;
	bool isValid = 0;
	while(!isValid)	{
		std::cout << prompt;
		std::getline(std::cin, input);

		if(input.empty()) {
			std::cout << "err: no input provided try again.\n";	
			continue;
		} else {
			isValid = 1;
		}
	}
	return input;
}

int inputInt(std::string prompt)
{
	// todo: add a validation for empty input
	int input;
	bool isValid = 0;
	while(!isValid)	
	{
		std::cout << prompt;
		std::cin >> input;

		if(std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore
			(
				std::numeric_limits<std::streamsize>::max(), 
				'\n'
			);
			std::cout << "err: invalid input detected.\n";
			continue;
		} else {
			isValid = 1;
		}
	}
	return input;
}

void getStudentData(students &data)
{
	data.name.push_back(inputStr("enter student name: "));	
	data.quiz.push_back(inputInt("enter student quiz(25%): "));
	data.act.push_back(inputInt("enter student activity(20%): "));
	data.lab.push_back(inputInt("enter student laboratory(25%): "));
	data.exam.push_back(inputInt("enter student exam(30%): "));
}

void displayStudents(students &data)
{
	std::cout << "\n";
	for(unsigned int i = 0; i < data.name.size(); i++) {
		std::cout << "name: " << data.name.at(i) << "\n";
		std::cout << "quiz: " << data.quiz.at(i) << "\n";
		std::cout << "activity: " << data.act.at(i) << "\n";
		std::cout << "laboratory: " << data.lab.at(i) << "\n";
		std::cout << "exam: " << data.exam.at(i) << "\n";
	}
}

void displayTopAndLow()
{
	std::cout << "displaying highest and lowest\n";
}

void sortStudentGrade()
{
	std::cout << "sorting students grade\n";
}

void printMenu()
{
	using namespace std;
	cout << "\n";
	cout << "[a] input student data\n";
	cout << "[b] display all student\n";
	cout << "[c] display top and lowest\n";
	cout << "[d] sort student grade(ascending)\n";
	cout << "[e] exit\n\n";
	cout << "enter input (a/b/c/d/e): ";
}

int main()
{
	students data;
}
