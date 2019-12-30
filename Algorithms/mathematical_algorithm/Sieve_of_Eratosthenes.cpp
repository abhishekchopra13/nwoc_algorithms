// Given a number n , print all primes number smaller than or equal to n.
// it is algo given n is smaller number
#include<bits/stdc++.h>
using namespace std;
void Sieve(int n)
{
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for(int i=2; i*i<=n;i++)
	{
		//if prime[i] is not changed , then it is a prime
		if(prime[i]==true)
		{
			for(int j=i*i; j<=n;j+=i)
			{
				prime[j]=false;
			}
		}
	}
	for(int p=2;p<=n;p++)
	{
		if(prime[p])
		cout<<p<<" ";
	}
	cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cout<<"Enter the number:"<<endl;
	cin>>n;
	Sieve(n);
	return 0;
}
