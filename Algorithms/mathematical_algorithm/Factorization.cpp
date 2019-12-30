//Given an number n, write an efficient function to print all prime factor of n
#include<bits/stdc++.h>
using namespace std;
void primeFactor(int n)
{
	while(n%2==0)
	{
		n=n/2;
		cout<<"2"<<" ";
	}
	for(int i=3;i<=sqrt(n);i=i+2)
	{
		while(n%i==0)
		{
			cout<<i<<" ";
			n=n/i;
		}
	}
	if(n>2)
	cout<<n<<" ";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cout<<"Enter the Number:"<<endl;
	cin>>n;
	primeFactor(n);
	return 0;
}
