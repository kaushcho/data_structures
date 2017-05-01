#include<iostream>
using namespace std;

int addition(int a,int b)
{ return a+b; }

int subtraction (int a,int b)
{ return a-b; }

int operation (int x,int y, int (*function)(int,int))
{
	int p=(*function)(x,y);
	return p;
}

int main()
{
	int m,n;
	int (*ghataav)(int,int) = subtraction;
	m = operation(5,20,addition);
	n = operation(m,5,ghataav);
	cout<<"Final result="<<n<<endl;
	return 0;
}

