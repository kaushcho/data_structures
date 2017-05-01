#include <iostream>
#include <vector>

using namespace std;

class Number_One {
	int number;
	string text;
	public:
	Number_One(int, string);
	Number_One();
	void NumberOneGet();
};
Number_One::Number_One(int num, string txt){
	number = num;
	text = txt;
}
Number_One::Number_One() {
	number = 10;
	text   = "Default Constructor";
}
void Number_One::NumberOneGet() {
	cout<<"Value of members in Number_One:"<<number<<" is "<<text<<endl;
}
class Number_Two {
	vector<Number_One*> numeroUno;
	public:
	int number2;
	Number_Two(int);
	void AccessNumberOne(Number_One &);
	void GetNumber_Two();
};
Number_Two::Number_Two(int num2){
		number2=num2;
}
void Number_Two::AccessNumberOne(Number_One &numOneObj) {
	Number_One *numbers = new Number_One(26,"My Age!");
	numeroUno.push_back(&numOneObj);
	numeroUno.push_back(numbers);
	numeroUno.push_back(new Number_One(25,"Mimi's Age!"));
}
void Number_Two::GetNumber_Two() {
	vector<Number_One*>::iterator iter;
	for(iter=numeroUno.begin();iter!=numeroUno.end();iter++) {
    Number_One *showOne = *iter;
	showOne->NumberOneGet();
	}
}
int main()
{
	Number_Two trial(5);
	Number_One num1Test(5000,"India's Age!");
	trial.AccessNumberOne(num1Test);
    cout<<"Value in number 2 is: "<<trial.number2<<endl;
	trial.GetNumber_Two();
	return 0;
}

