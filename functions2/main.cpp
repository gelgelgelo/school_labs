/*
	my thoughts:
	
	i hate the guts of this lab but i used it to my advantage.
	i really hate spending time not solving the problem and 
	i hate sanitizing input so im going all out on this shit
	ill sanitize every known input to man lol
	
	umm im now dealing with displaying top and lowest
	im kinda having trouble on what a function should do lol,
	like if i should care about modularity or just solve 
	the problem as fast as possible.

	todo: make the input in main only accept char `a` to `e`.

	hey im back i just realized i need to do the sorting first
	before displaying the hi and lo, this is gonna be hard since
	i plan on not looking up any algo and just creating my own
	from scratch and once done ill compare it to pre existing 
	sorting algos out there.

	im gonna sleep this thing still isnt done yet ill display the
	names and give them better formating but i need to sleep.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <cfloat>

struct studentData {
	std::vector<std::string> name = {};
	std::vector<int> quiz = {};
	std::vector<int> act = {};
	std::vector<int> lab = {};
	std::vector<int> exam = {};
};

struct errMsg {
	std::string noInput = "\nerr: no input provided.\n";
	std::string hasInt = "\nerr: int input detected, expecting str or char.\n";
	std::string hasStr = "\nerr: str input detected, expecting int.\n";
	std::string strTooLong = "\nerr: provided str is too long.\n"; 
	std::string intTooLong = "\nerr: provided int is too long.\n"; 
	std::string charTooLong = "\nerr: too long, input should be 1 char.\n";
};

bool strHasInt(std::string str)
{
	bool noInt = 0; 
	for(unsigned int i = 0; i < str.length(); i++) {
		if(isdigit(str[i]) == 1) {
			noInt = 1;
			return noInt;
			continue;
		} else {
			noInt = 0;
		}
	}	
	return noInt;
}

std::string inputStr(std::string prompt = "")
{
	errMsg err;
	std::string input;
	bool isValid = 0;
	while(!isValid) {
		std::cout << prompt;	
		std::getline(std::cin, input);
		if(input.empty()) {
			std::cout << err.noInput;
			continue;
		} else if(strHasInt(input)) {
			std::cout << err.hasInt;
			continue;
		// i think 64 is a sweetspot any thing shorter is nah.
		} else if(input.length() > 64) {
			std::cout << err.strTooLong;
			continue;
		} else {
			isValid = 1;
		}
	}	
	return input;
}

bool intHasStr(std::string str)
{
	std::string alpha= "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool noStr = 0; 
	for(unsigned int i = 0; i < str.length(); i++) {
		for(unsigned int j = 0; j < alpha.length(); j++) {
			if(str[i] == alpha[j]) {
				noStr = 1;
				return noStr;
				continue;
			} else {
				noStr = 0;					
			}
		}
	}	
	return noStr;
}

int inputInt(std::string prompt = "")
{
	errMsg err;
	std::string input;
	bool isValid = 0;
	while(!isValid) {
		std::cout << prompt;	
		std::getline(std::cin, input);
		if(input.empty()) {
			std::cout << err.noInput;
			continue;
		// just switched the order so it wont become expensive
		// once the input gets too big, also my justification
		// for the length of 4 is, no score has 4 digits.
		} else if(input.length() > 4) {
			std::cout << err.intTooLong;
			continue;
		} else if(intHasStr(input)) {
			std::cout << err.hasStr;
			continue;
		} else {
			isValid = 1;
		}
	}	
	return std::stoi(input);
}

bool charHasInt(std::string str)
{
	bool noInt = 0; 
	for(unsigned int i = 0; i < str.length(); i++) {
		if(isdigit(str[i]) == 1) {
			noInt = 1;
			return noInt;
			continue;
		} else {
			noInt = 0;
		}
	}	
	return noInt;
}

char inputChar(std::string prompt)
{
	errMsg err;
	std::string input;
	bool isValid = 0;
	while(!isValid) {
		std::cout << prompt;	
		std::getline(std::cin, input);
		if(input.empty()) {
			std::cout << err.noInput;
			continue;
		} else if(input.length() > 1) {
			std::cout << err.charTooLong;
			continue;
		} else if(charHasInt(input)) {
			std::cout << err.hasInt;
			continue;
		} else {
			isValid = 1;
		}
	}	
	return input[0];
}

void displayMenu() 
{
	std::cout << "\n\n";
	std::cout << "[a] input student data\n";
	std::cout << "[b] display all students\n";
	std::cout << "[c] display top and lowest student grade\n"; 
	std::cout << "[d] sort student grades\n";
	std::cout << "[e] exit the program\n";
	std::cout << "\n\n"; 
}

void getStudentData(studentData &data)
{
	data.name.push_back(inputStr("student name: "));
	data.quiz.push_back(inputInt("student quiz: "));
	data.act.push_back(inputInt("student activity: "));
	data.lab.push_back(inputInt("student laboratory: "));
	data.exam.push_back(inputInt("student exam: "));
}

void displayStudents(const studentData &data)
{
	for(unsigned int i = 0; i < data.name.size(); i++) { 
		std::cout << "--------------------------------\n";
		std::cout << "student name: " << data.name.at(i) << "\n";
		std::cout << "student quiz: " << data.quiz.at(i) << "\n";
		std::cout << "student activity: " << data.act.at(i) << "\n";	
		std::cout << "student lab: " << data.lab.at(i) << "\n";	
		std::cout << "student exam: " << data.exam.at(i) << "\n";	
		std::cout << "--------------------------------\n";
	}
}

std::vector<double> getStudentsWeightedAve(const studentData &data)
{
	std::vector<double> weightedAve = {};
	
	for(unsigned int i = 0; i < data.name.size(); i++) {
		double quiz = data.quiz.at(i) * 0.25;
		double act = data.act.at(i) * 0.20;
		double lab = data.lab.at(i) * 0.25;
		double exam = data.exam.at(i) * 0.30;
		double finalGrade = quiz + act + lab + exam;
		weightedAve.push_back(finalGrade);
	}
	//std::cout << "size of gswa.wa is: " << weightedAve.size() << "\n";
	return weightedAve;
}

std::vector<double> sortStudentsGrade(const studentData &data)
{
	std::vector<double> grades = getStudentsWeightedAve(data);			

	for(unsigned int i = 0; i < grades.size() - 1; i++) {
		int jMin = i;
		for(unsigned int j = i + 1; j < grades.size(); j++) {
			if(grades.at(j) < grades.at(jMin)) {
				jMin = j;
			}
		}
		double tmp = grades.at(i);
		grades.at(i) = grades.at(jMin);
		grades.at(jMin) = tmp;
	}

	return grades;
}

void displaySortedGrades(const studentData &data) 
{
	// lol im super lazy and just wanna get this done already
	std::vector<double> grades = sortStudentsGrade(data);	
	for(unsigned int i = 0; i < grades.size(); i++) {
		std::cout << grades.at(i) << "\n";		
	}
}

void displayTopNLowest(const studentData &data)
{
	// the instruction didnt say to include the name
	// im too tired for that lol maybe when im in the mood i will
	// all i need to do is find a match for hi/lo and then
	// print the name associated with that index
	std::vector<double> grades = sortStudentsGrade(data);
	double topGrade = DBL_MIN;
	double lowGrade = DBL_MAX;
	for(unsigned int i = 0; i < grades.size(); i++) {
		if(grades.at(i) > topGrade) {
			topGrade = grades.at(i);	
		}	

		if(grades.at(i) < lowGrade) {
			lowGrade = grades.at(i);	
		}	
	}
	
	std::cout << "highest grade: " << topGrade << "\n";
	std::cout << "lowest grade: " << lowGrade << "\n";
}


int main()
{
	studentData sData;
	char input = 'a';
	do {
		displayMenu();
		input = tolower(inputChar("> "));
		switch(input) {
		case 'a':
			getStudentData(sData);
			break;
		case 'b':
			displayStudents(sData);
			break;
		case 'c':
			displayTopNLowest(sData);
			break;
		case 'd':
			displaySortedGrades();
			break;
		}
	} while(input != 'e');	
}
