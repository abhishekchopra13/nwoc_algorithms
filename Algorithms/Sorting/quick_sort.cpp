// Program to sort an array in descending order using Quick Sort
// Language used: C++
// Description: Quick Sort works on Divide and Conquer algorithm. In this we take a pivot and partition the 
//              whole array around this pivot. We put the pivot at correct elements at correct position and
//              put all the smaller elements(smaller than pivot) after the pivot and all the greater elements 
//              before the pivot. 
// Author: ExpressHermes

#include <bits/stdc++.h>
using namespace std;

void quick_sort(int *ar, int n) 
{
    if(n < 2)
        return;

    int pivot = ar[n/2];
    int i, j;
    for(i = 0, j = n - 1; ;i++, j--)
    {
        while(ar[i] > ar[pivot]) i++;
        while(ar[j] < ar[pivot]) j--;

        if(i >= j)
         break;

        int temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
    }

    quick_sort(ar, i);
    quick_sort(ar + i, n - i);
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
    
    quick_sort(ar, n);

    for(int i = 0; i < n; i++)
        cout << ar[i] << " ";
        cout << endl;
}