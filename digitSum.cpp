// Sum of the digits


#include <iostream>

int digiSum(int n)
{
    int sum = 0;
    int rem = 10;
    int quo = 1;
    while (n/quo > 0)
    {
        sum += (n % rem)/quo;
        quo *= 10;
        rem *= 10;
    }
    return sum;
}

int main()
{
    int num = 0;
    std::cin >> num;
    std::cout << "The sum of the digits in "<<num<<" is: "<<digiSum(num)<<std::endl;
    return 0;
}
