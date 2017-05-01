#include <iostream>
#include <cstdlib>
using namespace std;

#define N 3
int main() {
    int m[N][N];
    int i = 0,j = 0;
    srand(time(NULL));
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            m[i][j] = rand() % 2;
            cout <<m[i][j]<<endl;

        }
    }
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            if((m[i][j+1]) || (m[i+1][j]))
                cout << "Impossible to make a move!"<<endl;
            else if(!m[i][j+1]) {
                cout <<"("<<i<<", "<<j+1<<")"<<endl;
                j++;
                continue;
            }
            else if(!m[i+1][j]) {
                cout <<"("<<i+1<<", "<<j<<")"<<endl;
                i++;
            }
        }
    }
    return 0;
}
