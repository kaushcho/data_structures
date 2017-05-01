#include<iostream>
using namespace std;
int main()
{
	int num, loop;
	int *dynMem;
	cout<<"How many numbers would you like to enter:";
	cin>>num;
	dynMem = new (nothrow) int[num];
	if (dynMem==0)
		cout<<"Error: System could not allocate memory requested!"<<endl;
	else
	{
		for (loop=0;loop<num;loop++)
		{
			cout<<"Enter number:";
			cin>>dynMem[loop];
		}
		cout<<"You have entered:"<<endl;
		for (loop=0;loop<num;loop++)
			cout<<dynMem[loop]<<", ";
		delete[] dynMem;
	}
	return 0;
}
