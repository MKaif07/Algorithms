#include <iostream>
using namespace std;

// O(log(n))
int binarySearch(int arr[], int l, int r, int key)
{
    if(l > r){
        return -1;
    } else{
        int mid = (l + r)/2;
        if(key == arr[mid]){
            return mid;
        } else if(key > arr[mid]){
            // key on right side of mid
            return binarySearch(arr, mid+1, r, key);
        } else{
            return binarySearch(arr, l, mid-1, key);
        }
    }
}

int main()
{

    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 1170;
    // cout << binarySearch(arr, 0, size - 1, key) << endl;
    int result = binarySearch(arr, 0, size, key);
    (result == -1)
        ? cout << "Key is not present" << endl
        : cout << "Key is present at " << result << endl;
    return 0;
}