#include <iostream>
#include <string>
#include <string.h>

int main()
{
    std::string inputWord;
    std::string output;
	const std::string vowels = "aeiou";
	const std::string consonants = "hklmnpw";
//	char tempOut[75]; // Words don't exceed 75 chars in length
	std::string tempOut;
	char *tempStr;
	char *strPos;
	size_t position;

	do 
    {
    	std::cin  >> inputWord;
		tempStr = const_cast<char *>(inputWord.c_str());
		for(int i=0;i<=strlen(tempStr);i++)
		{
			if((tempStr[i] == 'k' || tempStr[i] == 'm' || tempStr[i] == 'w') && (tempStr[i+1] == 'a' && tempStr[i+2] == 'i')&& i==0)
				tempOut.copy(tempStr,3,0);
			else if(tempStr[i] == 'a' && tempStr[i+1] == 'i' && i==0)
			{
				tempOut.copy(tempStr,2,0);
				tempOut += '-';
			}
			else if(consonants.find(tempStr[i])!=std::string::npos)
				tempOut += tempStr[i];
			else if((tempStr[i]=='w') && (tempStr[i+1]=='a' || tempStr[i+1]=='e' || tempStr[i+1]=='i'))
			{
				tempOut += 'v'; 
				tempOut += tempStr[i+1];
			}
			else if(vowels.find(tempStr[i]) == vowels.find(tempStr[i+1]))
			{
				tempOut += tempStr[i];
				tempOut += '-';
			}
			else if(strstr(tempStr,"kiu")!=NULL)
				tempOut += "tsiu";
			else if(vowels.find(tempStr[i])!=std::string::npos && consonants.find(tempStr[i+1])!=std::string::npos && vowels.find(tempStr[i+2])!=std::string::npos )
			//else if(vowels.find(tempStr[i])!=std::string::npos && consonants.find(tempStr[i+1])!=std::string::npos )
			{
				tempOut += tempStr[i];
				tempOut += '-';
//				tempOut += tempStr[i+1];
			}
			else if(((tempStr[i]=='a')&&(tempStr[i+1]=='e' || tempStr[i+1]=='o'||tempStr[i+1]=='u')) || ((tempStr[i]=='e' || tempStr[i]=='o')&& tempStr[i+1]=='i') || (tempStr[i]=='o' && tempStr[i+1]=='u'))
			{
				tempOut += tempStr[i];
				tempOut += tempStr[i+1];
			}
		//		tempOut.copy(tempStr, 3,tempStr-1);
			else if(consonants.find(tempStr[strlen(tempStr)-1])!=std::string::npos && vowels.find(tempStr[strlen(tempStr)])!=std::string::npos)
			{
				tempOut += tempStr[strlen(tempStr)-1];
				tempOut += tempStr[strlen(tempStr)];
			}
			else if(vowels.find(tempStr[strlen(tempStr)-1])!=std::string::npos && vowels.find(tempStr[strlen(tempStr)])!=std::string::npos)
			{
				tempOut += tempStr[strlen(tempStr)-1];
				tempOut += '-';
				tempOut += tempStr[strlen(tempStr)];
			}
			else if(vowels.find(tempStr[strlen(tempStr)])!=std::string::npos)
			{
				tempOut += tempStr[strlen(tempStr)];
				break;
			}

		}
			tempOut +="\n";
			output += tempOut;
			tempOut = "";
	}
    while(inputWord != "paupaa");
	std::cout<<output;
    return 0;
}
