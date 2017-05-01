#include<iostream>
#include<exception>
using namespace std;

int main()
{
	try
	{
		int* myArray = new int[10000000000000000000];
	}
	catch ( exception& e)
	{
		cout<<"Standard exception: "<<e.what()<<endl;
	}
	return 0;
}

