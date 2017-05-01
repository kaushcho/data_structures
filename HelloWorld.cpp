#include<iostream>
#include<stdlib.h>
using namespace std;

class CRectangle{
		int x,y;
	public:
		CRectangle(int, int);
//		void set_values(int,int);
		int area(void);
};
/*
void CRectangle::set_values(int a, int b) {
		x=a;
		y=b;
} */

CRectangle::CRectangle(int l, int b) {
		x = l;
		y = b;
}

int CRectangle::area(){
		return (x*y);
}

int main(){
		CRectangle rect(3,4);
//		rect.set_values(3,4);
		char *ptr;
		ptr = (char *)malloc(20);
		ptr = "Hello World";
		cout<<"Area of the rectangle= "<<rect.area()<<endl;
		return 0;
}
