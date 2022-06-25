#include <iostream>
#include <math.h>
using namespace std;

// O(root n)
int jumpSearch(int arr[], int n, int key){

    int jump = sqrt(n);
    int prev = 0;

    while(arr[jump] < key){
        prev = jump;
        jump += sqrt(n);
        if(prev >= n){
            return -1;
        }
    }

    while(prev < jump){
        if(arr[prev] == key){
            return prev;
        }
        prev++;
    }
    return -1;
}

int main(){
    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 200;
    cout << jumpSearch(arr, size, key);
    return 0;
}