#include <iostream>
using namespace std;

// Array with uniformly distributed elements
// Avg   : O(log (log (n)))
// worst : O(n)
int interpolationSearch(int arr[], int l, int n, int key){
    int pos = 0;
    if(l <= n && key >= arr[l] && key <= arr[n]){
        pos = l + ((double)(n - l)/(arr[n] - arr[l]))*(key - arr[l]);

        if(arr[pos] == key){
            return pos;
        }
        if (arr[pos] < key)
            return interpolationSearch(arr, pos + 1, n, key);

        if (arr[pos] > key)
            return interpolationSearch(arr, l, pos - 1, key);
        
    }
    return -1;
}

int main(){

    int arr[] = {10, 13,15, 26,28,30,50,56,58};
    int n = (sizeof(arr)/sizeof(arr[0])) - 1;
    // cout << n;
    int key = 28;
    cout << interpolationSearch(arr, 0, n, key);
    return 0;
}