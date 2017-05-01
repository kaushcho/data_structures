#include <iostream>
#include <iomanip>


int printTable(int n)
{
    int w = 1;
    int m = n;
    while(m>0)
    {
        w++;
        m /= 10;
    } 
    std::cout << w <<std::endl;
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            std::cout << std::setw(w+1) << i*j <<" ";
        }
        std::cout<<std::endl;
    } 
    return 0;
}

int main()
{
    int n = 0, res =0;
    std::cin>>n;
    res = printTable(n);
    return 0;
}
