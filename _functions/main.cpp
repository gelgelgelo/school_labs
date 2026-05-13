#include <iostream>
#include <climits>
#include <limits>

int GetGCD(int a, int b)
{
	int tmp = 0;
	while(b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}	
	return a;
}

int GetLCM(int a, int b)
{
	return (a * b) / GetGCD(a, b);	
}

int main()
{
	int a, b;
	bool isValid = 0;
	while(!isValid)
	{
		std::cout << "Enter the first number: ";
		std::cin >> a;
		std::cout << "Enter the second number: ";
		std::cin >> b;
		if(std::cin.fail() || a < 0 || b < 0) 
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
	int LCM = GetLCM(a, b);
	int GCD = GetGCD(a, b);

	std::cout << "GCD of " << a << " and " << b << " is: " << GCD << "\n";
	std::cout << "LCM of " << a << " and " << b << " is: " << LCM << "\n";
	std::cout << "Common Divisors of " << a << " and " << b << " is: ";
	for(int i = 1; i < GCD + 1; i++)
	{
		if(GCD % i == 0) 
		{
			if(i == GCD)
			{
				std::cout << i;
			}
			
			else
			{
				std::cout << i << ", ";
			}
		}
	}
	std::cout << std::endl;
}
