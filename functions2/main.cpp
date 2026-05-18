#include <iostream>
#include <vector>
#include <string>
#include <cfloat>

struct Student {
	std::string name;
	double quiz;
	double act;
	double lab;
	double exam;
};

double getAve(const Student &s)
{
	return (s.quiz * 0.25) + (s.act * 0.20) + (s.lab * 0.25) + (s.exam * 0.30); 
}

void displayStudents(std::vector<Student> &data)
{
	for(const auto &sData : data) {
		std::cout << "--------------------------------\n";
		std::cout << "name: " << sData.name << "\n";
		std::cout << "quiz: " << sData.quiz << "\n";
		std::cout << "act: " << sData.act << "\n";
		std::cout << "lab: " << sData.lab << "\n";
		std::cout << "exam: " << sData.exam << "\n";
		std::cout << "--------------------------------\n";
	}	
}

std::vector<Student> sortGrades(std::vector<Student> data)
{
	int n = data.size();
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - i - 1; j++) {
			if(getAve(data[j]) < getAve(data[j + 1])) {
				Student tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;	
			}
		}
	}
	return data;	
}

void displayHiandLo(std::vector<Student> &data)
{
	std::string hiName = data[data.size() - 1].name;
	std::string loName = data[0].name;
	double hiGrade = getAve(data[0]);
	double loGrade = getAve(data[data.size() - 1]);

	std::cout << "highest and lowest grade\n";
	std::cout << "--------------------------------\n";
	std::cout << hiName << ":" << hiGrade << "\n";
	std::cout << loName << ":" << loGrade << "\n";
	std::cout << "--------------------------------\n";
}

int main()
{
	std::vector<Student> sData = {
		{"Greedy Jewish", 69, 69, 69, 69},
		{"Nigger Killer", 99, 99, 99, 99},
		{"Stinky Indian", 50, 50, 50, 50},
	};

	std::vector<Student> sorted = sortGrades(sData);
	displayStudents(sData);
	displayHiandLo(sorted);
	displayStudents(sData);
	displayStudents(sorted);

	// todo: add input with super duper strict input validation.
}
