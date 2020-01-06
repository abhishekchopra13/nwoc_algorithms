//Algorithm Name: Binary Exponentiation 

#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD9 1000000009
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define endl "\n"
typedef long long ll;
using namespace std;

ll fast_power(ll n, ll k, ll p = MOD) {
ll r = 1; 
for (; k; k >>= 1)
 {
 if (k & 1) r = r * n%p; 
 n = n * n%p;
 } 
 return r;
 }
 




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
 ll a,b,c;
 cin>>a>>b>>c;
 ll ans=fast_power(a,b,c);
 cout<<ans<<endl; 
  return 0;
    
}

/*
Sample Input:
2 7 5
Sample Output:
3

Explanation:
The Input is 3 integers a,b,c.
The ouput is  (a raised to b)mod c.
Therefore 2^7=128 and 128%5=3.
We want to find (a raised to b ) mod c in logN time where N is the number of the bits in the binary  representation of b. The algorithm is called as Binary Exponentiation which uses the binary representation of b to compute the result in O(logN) time instead of O(b).
The details of the algorithm can be found at: https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/
 */
