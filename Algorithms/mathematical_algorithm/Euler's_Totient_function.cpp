//Euler's toient function ?(n) for an input n is count of numbers in {1,2,3,......n} that are relatively prime to n
// i.e., the number whose GCD with n is 1
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int fun(int n)
{
	int result=0;
	for(int i=1;i<n;i++)
	{
		if(gcd(i,n)==1)
		{
			result++;
		}
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cout<<"Enter the number:"<<endl;
	cin>>n;
	cout<<fun(n)<<endl;
	return 0;
}
