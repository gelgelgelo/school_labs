#include <iostream>

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
	std::cout << "Enter the first number: ";
	std::cin >> a;
	std::cout << "Enter the second number: ";
	std::cin >> b;
	int LCM = GetLCM(a, b);
	int GCD = GetGCD(a, b);

	std::cout << "GCD of " << a << " and " << b << " is: " << GCD << std::endl;
	std::cout << "LCM of " << a << " and " << b << " is: " << LCM << std::endl;
	std::cout << "Common Divisors of " << a << " and " << b << " is: ";
	for(int i = 1; i < GCD + 1; i++)
	{
		if(GCD % i == 0) 
		{
			std::cout << i << ",";
		}
	}
	std::cout << std::endl;
}

