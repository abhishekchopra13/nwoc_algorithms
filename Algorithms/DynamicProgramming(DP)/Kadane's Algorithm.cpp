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
	int t;
	cin>>t;;
	while(t--)
	{
	    int a;
	    cin>>a;
	    int arr[a];
	    for(int i=0;i<a;i++)
	    cin>>arr[i];
	    
	    cout<<kadanes(arr,a)<<endl;
	}
	return 0;
}