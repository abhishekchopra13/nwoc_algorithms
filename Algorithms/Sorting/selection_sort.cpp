// Program to sort an array in ascending order using Selection Sorting
// Language used: C++
// Description: In every iteration of selection sort, the minimum element (considering ascending order) 
//              from the unsorted subarray is picked and moved to the sorted subarray.
// Author: ExpressHermes

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) 
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void selection_sort(int *ar, int n) 
{
    for(int i = 0; i < n; i++)
    {
        int min_index = i;
        for(int j = i + 1; j < n; j++)
        {
            if(ar[j] < ar[min_index])
                min_index = j;
        }

        // place the element in it's right position
        swap(&ar[i], &ar[min_index]);
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
    
    selection_sort(ar, n);

    for(int i = 0; i < n; i++)
        cout << ar[i] << " ";
        cout << endl;
}