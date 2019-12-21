//Algorithm's Name: Catalan Number

#include<bits/stdc++.h>
#define MOD 1000000007
#define MOD9 1000000009
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define endl "\n"
typedef long long ll;
using namespace std;


const int MAX=1000000;
ll catalan[MAX];
ll catalan_number(ll n) {
    catalan[0] = catalan[1] = 1;
    for (int i=2; i<=n; i++) {
        catalan[i] = 0;
        for (int j=0; j < i; j++) {
            catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
            if (catalan[i] >= MOD) {
                catalan[i] -= MOD;
            }
        }
    }
    return catalan[n];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
ll n;
cin>>n;
ll x=catalan_number(n);
cout<<x<<endl;

  return 0;
    
}

/*
Sample Input:
5
Sample Output:
42

Explanation:
The Input takes an integer N and the output is the Nth Catalan Number.
Catalan Numbers are (2nCn)/(n+1) where C is thee binomial coefficient.
These are special types of numbers which denotes the pattern in many competitive coding contests.
These numbers were found by Belgian mathematician Catalan.
In Input give which Catalan number you want to find.
The function catalan_number computes it and returns the result which is printed.
For more information on Catalan Numbers:https://en.wikipedia.org/wiki/Catalan_number
*/
