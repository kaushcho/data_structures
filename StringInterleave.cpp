#include<iostream>
#include<string>

using namespace std;
bool IsInterleaved(string, string, string);
int main()
{
	
	string str1, str2, strInt,result;
	bool Interleaved;
	cout<<"Enter the first and second strings:"<<endl;
	cin>>str1>>str2;
	cout<<"The two strings you entered are: "<<str1<<" and "<<str2<<endl;
	cout<<"Enter the third string (should consist of the first two strings you entered)"<<endl;
	cin>>strInt;
	Interleaved = IsInterleaved(str1,str2,strInt);
	if(!Interleaved) 
		result="NOT";
	else
		result="INDEED";

	cout<<"The string you entered is: "<<strInt<<" and it is "<<result<<" perfectly interleaved! with "<<str1<<" and "<<str2<<"."<<endl;
	return 0;
}

bool IsInterleaved(string str1, string str2, string Int)
{
	if(Int.length() != str1.length() + str2.length());
        return false;

    const char* word1   =new char[str1.length()];
	const char* word2   = new char[str2.length()];
	const char* wordInt = new char[Int.length()];
    

	word1   = str1.c_str();
	word2   = str2.c_str();
	wordInt = Int.c_str();



	delete word1,word2,wordInt;

	return true;
}
