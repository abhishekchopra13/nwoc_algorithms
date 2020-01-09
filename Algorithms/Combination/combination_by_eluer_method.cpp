//Combination computation by Euler method
//Language Used: C++
//Combination calculation of large numbers is difficult
//Euler method performs well with large numbers
//Output: This algorithm will give the nCr value of two numbers
// Sample Input:
// N = 5   R = 3
// Sample Output:
// The value of nCr for numbers 5 and 3 is 10


//author:Aditya Kothari
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1000000007

long long f[100001];

ll pow(ll a, ll b, ll MOD)
{
 ll x=1,y=a;
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD;
 	b /= 2;
 	}
 return x;
}
/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
ll InverseEuler(ll n, ll MOD)
{
 return pow(n,MOD-2,MOD);
}

ll C(ll n, ll r, ll MOD)
{

 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int main(){
	f[0] = 1;
	for(int i = 1 ; i <= 100000 ; i++)
		f[i] = (f[i-1]*i)%INF;
    ll n,r,ans;
    cout<<"Enter the value of N\n";
    cin>>n;
    cout<<"Enter the value of R\n";
    cin>>r;
 	ans=C(n,r,INF);
 	cout<<"The value of nCr for numbers "<<n<<" and "<<r<<" is "<<ans<<"\n";
}
