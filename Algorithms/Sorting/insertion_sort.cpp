// Program to sort an array in ascending order using Insertion Sorting
// Language used: C++
// Description: In insertion sort, we pick an element a[i] and we 
//              insert into it's right position in the sorted subarray ar[0] and ar[i-1]
// Author: ExpressHermes

#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int *ar, int n) 
{
    for (int i = 1; i < n; i++) 
    {  
        int value = ar[i];  
        int j = i - 1;  
  
        while (j >= 0 && ar[j] > value) 
        {  
            ar[j + 1] = ar[j];  
            j = j - 1;  
        }  
        ar[j + 1] = value;  
    }  
}

int main() 
{
    int n;
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    int ar[n];
    cout << "Enter the elements of array: " << endl;
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    
    insertion_sort(ar, n);

    for(int i = 0; i < n; i++)
        cout << ar[i] << " ";
        cout << endl;
}