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
	while(!isValid)	
	{
		std::cout << prompt;
		std::getline(std::cin, input);

		if(input.empty())
		{
			std::cout << "err: no input provided try again.\n";	
			continue;
		}

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore
			(
				std::numeric_limits<std::streamsize>::max(), 
				'\n'
			);
			std::cout << "err: invalid input detected.\n";
			continue;
		}
		
		else
		{
			isValid = 1;
		}
	}
	return input;
}

int inputInt(std::string prompt)
{
/*
	i didnt put that much effort to handling errors since im more focused
	on actually solving the problem.
*/
	int input;
	bool isValid = 0;
	while(!isValid)	
	{
		std::cout << prompt;
		std::cin >> input;

		if(std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore
			(
				std::numeric_limits<std::streamsize>::max(), 
				'\n'
			);
			std::cout << "err: invalid input detected.\n";
			continue;
		}
		
		else
		{
			isValid = 1;
		}
	}
	return input;
}

void getStudentName(students &data)
{
	// im so proud of this lmao, its like the python `input()` function.
	data.name.push_back(inputStr("enter student name: "));	
}

void getStudentQuiz(students &data)
{
	data.quiz.push_back(inputInt("enter student quiz(25%): "));
}

void getStudentAct(students &data)
{
	data.act.push_back(inputInt("enter student activity(20%): "));
}

void getStudentLab(students &data)
{
	data.lab.push_back(inputInt("enter student laboratory(25%): "));
}

void getStudentExam(students &data)
{
	data.exam.push_back(inputInt("enter student exam(30%): "));
}

void printMenu()
{
	// bruh i suck at ux and ui
	using namespace std;
	cout << "\n";
	cout << "[a] input student data\n";
	cout << "[b] display all student\n";
	cout << "[c] display top and lowest\n";
	cout << "[d] sort student grade(ascending)\n";
	cout << "[e] exit\n\n";
}

int main()
{
	students data;
	
	printMenu();	
	char input = 'a';
		
}
