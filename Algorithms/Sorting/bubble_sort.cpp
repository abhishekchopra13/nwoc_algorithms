// Program to sort an array in ascending order using Binary Sorting
// Language used: C++
// Description: In binary sort, we constantly swap the adjacent elements in wrong order
// Author: ExpressHermes

#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) 
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubble_sort(int *ar, int n) 
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-i-1; j++)
        {
            if(ar[j] > ar[j+1])
            {
                // swap elements in the wrong order
                swap(&ar[j], &ar[j+1]);
            }
        }

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
    
    bubble_sort(ar, n);

    for(int i = 0; i < n; i++)
        cout << ar[i] << " ";
        cout << endl;
}