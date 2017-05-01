#include <iostream>
#include <fstream>
#include <cstdlib>
int main() {
    int N = 0;
    int i = 0;
    int range = 0;
    std::ofstream randFile;
    std::cout <<"Enter number of random numbers to generate and range"<<std::endl;
    std::cin  >> N >> range;
    randFile.open("randInt.txt");
    srand(time(NULL));
    for(i=0;i<N;i++) {
        randFile << rand() % range + 1<<" ";
    }
    randFile.close();
    return 0;
}

