#include <iostream>
#include <vector>
#include <string>

struct studentsData 
{
	std::vector<std::string> name = {};
	std::vector<int> quiz = {};
	std::vector<int> activity = {};
	std::vector<int> laboratory = {};
	std::vector<int> exam = {};
};

void getStudentsName(studentsData &data)
{
	std::string input;
	std::cout << "enter student name: ";
	std::getline(std::cin, input);			
	data.name.push_back(input);
}

int main()
{
	studentsData sData;
}
