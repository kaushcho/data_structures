#include <iostream>

int printSum(int num1, int num2)
{
	return num1+num2;
}

int main()
{
	int n1, n2;
	std::cout << "Enter two numbers to add:" << std::endl;
	std::cin >> n1 >> n2;
	std::cout << "The sum of the two numbers you entered is: " << printSum(std::move(n1), std::move(n2)) << std::endl;
	//std::cout << "The sum of the two numbers you entered is: " << printSum(n1, n2) << std::endl;
	return 0;
}

