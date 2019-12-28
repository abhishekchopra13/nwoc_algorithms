//LCM of two numbers is the smallest number which can be divided by both numbers
// a*b=LCM(a,b) * GCD(a,b)
#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
int LCM(int a,int b)
{
	return (a*b)/gcd(a,b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(); cout.tie(NULL);
	int a,b;
	cout<<"Enter the both number's:"<<endl;
	cin>>a>>b;
	cout<<LCM(a,b)<<endl;
	return 0;
}
