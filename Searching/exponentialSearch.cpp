#include <iostream>
using namespace std;

int binarySearch(int[], int, int, int);

int exponentialSearch(int arr[], int n, int x){
    if(arr[0] == x){
        return 0;
    }

    int i = 1;
    while(i < n && arr[i] <= x){
        i = i*2;
    }
    return binarySearch(arr, i/2, i, x);
}

int binarySearch(int arr[], int l, int r, int x){
    if(r>=l){
        int mid = (l + r)/2;

        if(arr[mid] == x){
            return mid;
        }

        if(arr[mid] > x){
            return binarySearch(arr, l, mid-1, x);
        }

        return binarySearch(arr, mid+1, r, x);
    }

    return -1;
}

int main(){

    int arr[] = {2,3,4,10,40,50,70};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 100;
    int res = exponentialSearch(arr, n, x);
    (res == -1) ? cout << "Element not present" : cout << "Element at " << res; 
    return 0;
}