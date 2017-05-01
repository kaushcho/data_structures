#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len   = sizeof(arr)/sizeof(int);
    cout<<len<<endl;
    int i;
    for(i=0;i<len;i++)
        cout<<arr[i]<<" ";
    for (i=0;i<len-1;i++)
    {
        arr[i] = (arr[i] << 1) | ((arr[i+1] >> 31) & 1);
    }
    arr[len-1] = arr[len-1] << 1;
    cout << endl;
    for(i=0;i<len;i++)
        cout<<arr[i]<<" ";
    cout << endl;
    return 0;
}

