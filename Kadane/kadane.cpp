//MAXIMUM SUM OF SUBARRAY(CONTIGUOUS SUBSEQUENCE) KADANE'S ALGO
 //Sample Input:
 //Enter length of Array : 4
 //Enter elements of Array
 //4 5 3 5
 //Sample Output:
 //17

#include <bits/stdc++.h>

using namespace std;

int kadMax(int arr[], int size)
{    
    int final_max = INT_MIN, current_max = 0; //INT_MIN = MOST NEGATIVE INTEGER
    
    for(int i = 0; i < size; i++)
    {
        //Iterate over Array adding each element to current max
        current_max = current_max + arr[i];
        
        //finalMax updated when less than currentMax
        if(final_max < current_max)
            final_max = current_max;
        
        //If currentMax becomes negative it is reassigned value 0
        if(current_max < 0)
            current_max = 0;
    }
    
    return final_max;
}

int main()
{
    int len, ans;
    
    cout << "Enter length of Array : ";
    
    cin >> len;
    
    int ar[len];
    
    cout<<"Enter elements of Array\n";
    
    for(int i = 0; i < len; i++) //Array Input
        cin >> ar[i];
    
    ans = kadMax(ar, len); //Function calling
    
    cout<<ans<<endl;
    
    return 0;
}
