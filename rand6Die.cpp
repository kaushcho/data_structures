#include <iostream>
#include <cstdlib>

using namespace std;

const int DIESIZE = 6;
const int ADJ     = 1;
void throwDice(int *res)
{
    static bool firstTime = true;
    if(firstTime)
    {
        srand((unsigned int)time(NULL));
        firstTime = false;
    }
    *res = rand() % DIESIZE + ADJ;
}

int main()
{
    int res = 0;
    char ans;
    cout << "Enter any character to throw dice and (N/n) to stop!" << endl;
    cin  >> ans;
    while (toupper(ans) != 'N')
    {
        throwDice(&res);
        cout << "The dice returned a: " << res << endl;
        cout << "Would you like to throw the dice again? ((n/N) to exit)" << endl;
        cin  >> ans;
    }
    return 0;
}
