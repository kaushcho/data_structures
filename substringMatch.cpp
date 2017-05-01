#include <iostream>
#include <cstring>
using namespace std;

int findMatch(char pat[], char text[]) {
    int i=0, j=0;
    int m=0, n=0;

    m = strlen(pat);
    n = strlen(text);

    for(i=0;i<=n;i++) {
        for(j=0;j<m && (pat[j]==text[i+j]);j++)  {
                if(j+1==m)
                    return i;
        }
    }
    
    return -1;
}

int findMatch2(char pat[], char text[]) {
    int i=0, j=0;
    int m=0, n=0;

    m = strlen(pat);
    n = strlen(text);

    for(i=0;i<=n;i++) {
         while((j<m) && (text[i+j]==pat[j]))
            j = j+1;
            if(j==m)
                    return i;
    }
    
    return -1;
}
int main() {
    char text[]="The first job were found in the valley ABCD XYZW MNOP QRST";
    char pattern[] = "jobs";
    int found = 0;
    found = findMatch(pattern, text);
    if(found==-1)
        cout<<"Pattern "<<pattern<<" not found in the given text."<<endl;
    else
        cout<<"Pattern "<<pattern<<" found in the given text at position: "<<found<<"."<<endl;
    
    return 0;
}
