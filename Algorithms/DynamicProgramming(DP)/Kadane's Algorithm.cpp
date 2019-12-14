// Kadane's Algorithm
// Language Used: C++
// Kadane's algorithm to find maximum sum of the contiguous sub-array in linear time complexity
// Input Format: The first line of input contains an integer T denoting the number of test cases.The first line of each test case contains a single integer N denoting the size of array.
//               The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.
// Output Format: Print the maximum sum of the contiguous sub-array in a separate line for each test case.

// Sample Input: 2    -> Represent no of test cases.
//               5    		
//  		 1 2 3 -2 5
//		 4
// 		-1 -2 -3 -4

// Sample Output:  9
//		  -1


#include <bits/stdc++.h>
using namespace std;

int kadanes(int arr[],int a)
{
    int current=arr[0];
    int global=arr[0];
    for(int i=1;i<a;i++)
    {
        if(arr[i]>current+arr[i])
        current=arr[i];
        else
        current=(current+arr[i]);
        
        if(current>global)
        global=current;
    }
    
    return global;
}

int main() {
	int testcase;
	cin>>testcase;
	while(testcase--)
	{
	    int size;
	    cin>>size;
	    int arr[size];
	    for(int i=0;i<size;i++)
	    cin>>arr[i];
	    
	    cout<<kadanes(arr,size)<<endl;
	}
	return 0;
}
