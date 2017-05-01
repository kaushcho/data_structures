#include <iostream>
#include <algorithm>
#include <list>
#include <vector>


int main()
{
//    std::list <std::string> l1;
    std::vector <std::string> l1;
    l1.push_back("Hello");
    l1.push_back("Hi");
    l1.push_back("Hey");
    l1.push_back("Greetings");

//    std::list <std::string> iterator it;
    std::vector <std::string> iterator it = l1;
    return 0;
}

