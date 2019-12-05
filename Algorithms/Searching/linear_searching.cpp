// Linear Searching in CPP 
// code by @ExpressHermes


#include <bits/stdc++.h>
using namespace std;

int linear_search(int *ar, int n, int key)
{
    int found = 0, i;
    for(i = 0; i < n - 1; i++)
    {
        if(ar[i] == key)
        {
            found = 1;
            break;
        }
    }

    if(found == 1)
     cout << "The key is present in the array at index: " << i << endl;
    else
     cout << "The key is not present in the array" << endl;
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

    linear_search(ar, n, key);

}