/* Write a code to find distinct elements from a 
 * array containing elements in running form 
 * eg {111111111112222222222222333333333555} 
 * should give 1,2,3,5 as output.
 */

#include <iostream>
#include <cstring>
int main()
{
    int index = 0;
    const char* arr = "111111111112222222222222333333333555";
    bool charSet[256] = {false};
    for (int i = 0; i < strlen(arr);i++)
    {
        index = arr[i];
        if(charSet[index] == false)
            charSet[index] = true;
    }
    
    for (int i = 0; i < 255;i++)
    {
        if (charSet[i] == true)
            std::cout << (char)i<<", ";
    }
    std::cout<<std::endl;

    return 0;
}


