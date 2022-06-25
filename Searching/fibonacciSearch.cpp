#include <iostream>
using namespace std;

// it's like binary search 
// divides array into unequal parts 
int fibonaccianSearch(int arr[], int x, int n)
{
    int fib2 = 0; // (m-2)'th Fibonacci No.
    int fib1 = 1; // (m-1)'th Fibonacci No.
    int fib = fib2 + fib1; // m'th Fibonacci

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib != 0) {
        int i = min(offset + fib2, n - 1);
   
        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
   
        else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }

        else
            return i;
    }
   
    if (fib1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int fib(int arr[], int n, int x){
    int fib2 = 0, fib1 = 1;
    int fib = fib2 + fib1;

    while(fib < n){
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;
    
    while(fib > 0){
        int i = min(offset+fib2, n-1);
        if(arr[i] < x){
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if(arr[i] > x){
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
            return i;

        if(fib1 && arr[offset+1] == x){
            return offset + 1;
        }

        return -1;
    }
}

int main(){
    int arr[]
        = { 10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100,235};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 235;
    cout << fibonaccianSearch(arr, x, n);
    return 0;
}