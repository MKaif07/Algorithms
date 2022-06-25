#include <iostream>
using namespace std;

// O(n)
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

// O(n/2)
int linearSearch2(int arr[], int n, int key)
{
    int right = 0, left = n - 1;
    while (left >= right)
    {
        cout << left << " " << right << endl;
        if (key == arr[left])
        {
            return left;
        }
        if (key == arr[right])
        {
            return right;
        }
        left--;
        right++;
    }
    return -1;
}

int linearSearchRec(int arr[], int n, int x){
    int res;
    if(n >= 0){
        if(arr[n] == x){
            return n;
        } else{
            res = linearSearchRec(arr, n-1, x);
        }
    }else{
        return -1;
    }
    return res;
}

int main()
{

    int arr[] = {10, 20, 80, 30, 60, 50, 110, 100, 130, 170};
    int size = (sizeof(arr) / sizeof(arr[0])) - 1;
    int key = 10;
    cout << size << endl;
    cin >> key;

    // cout << linearSearch(arr, size, key) << endl;
    // cout << linearSearch2(arr, size, key) << endl;
    cout << linearSearchRec(arr, size, key);
    return 0;
}