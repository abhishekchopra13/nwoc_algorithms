//Algorithm Name:Euler's Totient Function

/*
Explanation:
The numbers from 1 to 5 which are co-prime with 5 are 1,2,3,4  i.e. 4 numbers.
The Input takes an integer N.
The output is the number of integers from 1 to N inclusive that are co-prime to N.
Euler's totient function, also known as phi-function  counts the number of integers between 1 and n inclusive, which are coprime to n. 
These numbers were found by mathematician Euler.

The function EulerTotient computes number of integers between 1 and n inclusive, which are coprime to n. 
and returns the result which is printed.
For more information on Euler Totient : https://en.wikipedia.org/wiki/Euler%27s_totient_function
*/

#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD9 1000000009
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define endl "\n"
typedef long long ll;
using namespace std;


ll EulerTotient(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
ll n;
cin>>n;
ll x=EulerTotient(n);
cout<<x<<endl;
  
  return 0;  
}

/*
Sample Input:
5
Sample Output:
4


*/
