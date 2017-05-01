#include <iostream>

using namespace std;

void selectionSort (int arr[],int n) {
    int i=0, j=0;  // counters
    int min = 0;   //min element

    for(i=0;i<n;i++) {
        min = arr[i];
        for(j=i;j<n;j++) {
            if(arr[j]<arr[i]) {
                min = arr[j];
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main() {
    int array[] = {7,9,2,1,5,8,0,4,6,3};
    cout << "\tThe given array is: ";
    for (int i=0;i<10;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    cout<<"\tThe sorted array is: ";
    selectionSort(array,10);
    for (int i=0;i<10;i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}

