#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

int main()
{
		string Input;
		char *InputChar;
    bool flag = false;
		while(Input != "Ahuihou")
		{
				cout<<"\tEnter word (let's see if you know any Hawaiian words)"<<endl;
				cin>>Input;
				InputChar = const_cast<char*>(Input.c_str());
				cout<<"\tProcessing word..."<<endl;
				sleep(1);
				while(*InputChar != '\0')
				{
								
						if((*InputChar == 'a') || (*InputChar == 'e') || (*InputChar == 'i') || (*InputChar == 'o') || (*InputChar == 'u') || (*InputChar == 'j') ||
							 (*InputChar == 'k') || (*InputChar == 'l') || (*InputChar == 'm') || (*InputChar == 'p') || (*InputChar == 'w') || (*InputChar == 'h') ||
							 (*InputChar == 'A') || (*InputChar == 'E') || (*InputChar == 'I') || (*InputChar == 'O') || (*InputChar == 'U') || (*InputChar == 'J') ||
							 (*InputChar == 'K') || (*InputChar == 'L') || (*InputChar == 'M') || (*InputChar == 'P') || (*InputChar == 'W') || (*InputChar == 'H'))
						{
								InputChar++;
								flag = true;
						}
						else
						{
								flag = false;
								break;
						}
				}

				if(flag)
						cout<<"\tAe"<<endl;
				else
						cout<<"\tNo"<<endl;
				
		}

		cout<<"\tOops! Looks like you entered the curse word. Program stopping..."<<endl;
		sleep(1);
		cout<<"\tGood Bye"<<endl;
		return 0;

}
