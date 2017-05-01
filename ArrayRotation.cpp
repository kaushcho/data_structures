
#include <iostream>
#include <vector>

using namespace std;

vector<int> array_left_rotation(vector<int> a, int n, int k) {
    
    vector<int> retVec;
    retVec.reserve(a.size());
    if ( n <= 0 || k <= 0)
        return a;
    if( n == k)
        retVec = a;
    else if (k < n)
    {
        for (int i = 0, j = k; j < n; i++, j++)
            retVec[i] = a[j];
        for (int i = n - k, j = 0; i < n ; i++, j++)
            retVec[i] = a[j];
    }
    else 
    {
        for (int i = 0, j = k % n; j < n; i++, j++)
            retVec[i] = a[j];
        for (int i = n - (k % n), j = 0; i < n; i++, j++)
            retVec[i] = a[j];

    }
    return retVec;

}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}