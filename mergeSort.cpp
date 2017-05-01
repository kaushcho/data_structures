#include <iostream>
#include <fstream>

#define RANGE 6 

void mergeSort(int, int, int []);
void merge(int, int, int, int []);
int main() {
    int i=0, arr[RANGE];
    std::ifstream numbers;
    numbers.open("randInt.txt");
    for(i=0;i<RANGE;i++) {
        numbers >> arr[i];
    }
    mergeSort(0, RANGE-1, arr);
    for(i=0;i<RANGE;i++)
        std::cout << std::endl << arr[i] << " ";
    std::cout<<std::endl;
    return 0;
}
void mergeSort(int low, int high, int arr[]) {
    int mid = 0;
    if(low<high) {
        mid = (low+high)/2;
        mergeSort(low, mid, arr);
        mergeSort(mid+1, high, arr);
        merge(low, mid, high, arr);
    }
}
void merge(int low, int mid, int high, int arr[]) {
    int i = 0, l =0, m=0, k=0, temp[RANGE];
    l = low;
    m = mid+1;
    i = low;

    while((l <= mid) && (m <= high)) {
        if(arr[l] <= arr[m]) {
            temp[i] = arr[l];
            l++;
        }
        else {
            temp[i] = arr[m];
            m++;
        }
        i++;
    }

    if (l > mid) {
        for(k = m; k <= high; k++) {
            temp[i] = arr[k];
            i++;
        }
    }
    else {
        for(k=l; k <= mid; k++) {
            temp[i] = arr[k];
            i++;
        }
    }

    for (k=low;k<=high;k++)
        arr[k]=temp[k];
}
