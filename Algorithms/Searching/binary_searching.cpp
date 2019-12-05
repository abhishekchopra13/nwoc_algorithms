// Program to search in an array using binary search
// Language used: C++
// Author: ExpressHermes

#include <bits/stdc++.h>
using namespace std;

int binary_search(int *ar, int low, int high, int key)
{
    if(high < low)
        return -1;

    int mid = low + (high - low) / 2;
    if(key == ar[mid])
        return mid;
    else if(key < ar[mid])
        return binary_search(ar, low, mid - 1, key);
    else if(key > ar[mid])
        return binary_search(ar, mid + 1, high, key);

}

int main()
{
    int n, key;
    cout << "Enter the size of array: ";
    cin >> n;
    int ar[n];
    cout << "Enter the elements: " << endl;
    for(int i = 0; i < n; i++)
        cin >> ar[i];

    cout << "Enter the value to be searched: ";
    cin >> key;    

    int result =  binary_search(ar, 0, n-1, key);

    if(result == -1)
        cout << "The key is not present in the array" << endl;
    else
        cout << "The key is present in array at index: " << result << endl;
    

}