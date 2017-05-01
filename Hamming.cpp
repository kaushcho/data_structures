#include<iostream>
#include<string.h>
using namespace std;
int hammingDist(char *, char *);
int main(int argc, char *argv[])
{
    int dist   = 0;
    
    if(argc!= 3)
    {
        cout<<"You did not enter the correct number of arguments!"<<endl;
        cout<<"Correct sequence of arguments: hammingdist <string1> <string2>"<<endl;
        return -1;
    }

    dist = hammingDist(argv[1], argv[2]);
    cout<<"Hamming distance between "<<argv[1]<<" and "<<argv[2]<< " is "<<dist<<"."<<endl;
    return 0;
}
int hammingDist(char *str1, char *str2)
{
    int dist   = 0;
    if(strlen(str1) == strlen(str2))
    {
        while(*str1 != '\0')
        {
            while(*str1++ ^ *str2++)
            {
                ++dist;
                if(*str1 == '\0')
                    break;
            }
        }
    }
    else 
    {
        cout<<"The strings you entered do not match in length. I cannot therefore, calculate the Hamming distance!"<<endl;
    }
    return dist;
}
