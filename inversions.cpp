#include <iostream>
#include <fstream>

#define RANGE 8

int mergeSort(int, int, int []);
int merge(int, int, int, int []);
int main() {
    int i=0, inv=0, arr[RANGE];
    std::ifstream numbers;
    numbers.open("randInt.txt");
    for(i=0;i<RANGE;i++) {
        numbers >> arr[i];
    }
    inv = mergeSort(0, RANGE-1, arr);
    for(i=0;i<RANGE;i++)
        std::cout << std::endl << arr[i] << " ";
    std::cout<<"Inversions = "<<inv<<std::endl;
    return 0;
}
int mergeSort(int low, int high, int arr[]) {
    int mid = 0, inv =0;
    if(low<high) {
        mid = (low+high)/2;
        mergeSort(low, mid, arr);
        mergeSort(mid+1, high, arr);
        inv += merge(low, mid, high, arr);
    }
    return inv;
}
int merge(int low, int mid, int high, int arr[]) {
    int i = 0, l =0, m=0, k=0, inv=0, temp[RANGE];
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
            inv++;
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
