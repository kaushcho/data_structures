#include<iostream>
using namespace std;
enum CodeRateHP {CR2 = 0, CR3 = 1, CR4 = 2, CR6 = 3, CR5 = 4};
void print(CodeRateHP cdrt);
int main(){

	enum CodeRateHP cdr;
	cdr = CR4;
	print(cdr);
	cdr=CR6;
	print(cdr);
	return 0;
}
void print(CodeRateHP cdrt) {
	cout<<"Value of enum type: "<<cdrt<<endl;
}
