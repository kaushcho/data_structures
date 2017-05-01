#include <iostream>
#include <math.h>
int main()
{
    int num = 0;
    std::cin >> num;
    if (num < 0)
    {
        std::cout << "Negative numbers cannot be evaluated for primality."<<std::endl;
        return -1;
    }
    else if(num > 2 && num % 2 == 0 || num == 1)
    {
        std::cout << "Number not prime" << std::endl;
        return -1;
    }
    else if(num == 2)
    {
        std::cout << "Number prime" << std::endl;
        return -1;
    }
    else
    {
        for(int i = 2;i <= sqrt(num);i++)
        {
            if(num % i == 0)
            {
                std::cout << "Number not prime" <<std::endl;
                return -1;
            }
        }
        std::cout << "Number is prime"<<std::endl;
    }
    return 0;
}
