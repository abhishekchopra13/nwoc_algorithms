// GCD OR HCF of two numbers is the largest number that divides both of them
#include<bits/stdc++.h>
using namespace std;
//GCD of two number does not change if smaller number is subtracted from a bigger number
int Euclidean(int a,int b)
{	
   if(a==0)
   return b;
   if(b==0)
   return a;
   //base case
   if(a==b)
   return a;
   //a is greater
   if(a>b)
   {
   	return Euclidean(a-b,b);
   }
   else
   return Euclidean(a,b-a);
}
int Euclidean1(int a,int b)
{
	if(b==0)
	return a;
	return Euclidean1(b,a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int a,b;
	cout<<"Enter both number's:"<<endl;
	cin>>a>>b;
	cout<<Euclidean(a,b)<<endl;
	cout<<Euclidean1(a,b)<<endl;
	return 0;
}
