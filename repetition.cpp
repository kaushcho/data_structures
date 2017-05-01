/* we are given a char array like “a1b2c3″ we have to convert 
 * this array to array like this “abbccc” .This has to be done 
 * in place as we have given that array has just enough space 
 * to hold the expanded array.
 */

#include <iostream>
#include <cstring>
#include <map>

// Create character map. A hash table can be used but I use a map data structure
// to maintain order. Replace map with unordered_map to create hashtable.
// Map contains the character and the frequency assuming input consistency.
// Input validation may be added by ensuring that every second character in
// the array is a digit. A primitive sanity check is already included in this code.
// The character frequency is used to rewrite the given array with the given
// character and the corresponding frequency.
void convert(char *arr) 
{
    // Map to store character and frequency
    std::map<char,int> charMap;
    int rep = 0, ctr = 0, freq = 0;
    for(int i = 0; i < strlen(arr); i++)
    {
        if(isdigit(arr[i+1]))
        {
            freq = arr[i+1] - '0'; // convert frequency from char to int
            charMap[arr[i]] = freq;
        }
    }
    // auto iterator. Use -std==c++0x while compiling. A new feature
    // in c++0x that makes the iterator auto discover the container type! w00t!
    for(auto it = charMap.begin();  it != charMap.end(); it++)
    {
        for(rep = 0; rep < it->second; rep++, ctr++)
        {
            arr[ctr] = it->first; // index on ctr to remember position in arr through iterations
        }
    }
}
int main()
{
    char *arr = new char[26*10]; // number of possible alphabets * number of possible digits
    std::cin  >> arr;
    convert(arr);
    std::cout << arr << std::endl;
    return 0;
}
