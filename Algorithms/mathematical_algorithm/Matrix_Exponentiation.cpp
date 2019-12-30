//C++ program to find value of f(n) where f(n) is defined as 
// f(n)=f(n-1)+ f(n-2)+ f(n-3), n>=3
//Base cases:
//f(0)=0, f(1)=1, f(2)=1;
#include<bits/stdc++.h>
using namespace std;
void multiply(int a[3][3],int b[3][3])
{
	int mul[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			mul[i][j]=0;
			for(int k=0;k<3;k++)
			{
				mul[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	a[i][j]=mul[i][j];
}
int power(int f[3][3],int n)
{
	int m[3][3]={{1,1,1},{1,0,0},{0,1,0}};
	// multiply with the initial value
	if(n==1)
	return f[0][0]+f[0][1];
	power(f,n/2);
	multiply(f,f);
	if(n%2!=0)
	multiply(f,m);
	
	return f[0][0]+f[0][1];
}
int findNth(int n)
{
	int f[3][3]={{1,1,1},{1,0,0},{0,1,0}};
	//base case
	if(n==0)
	return 0;
	if(n==1||n==2)
	return 1;
	
	return power(f,n-2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cout<<"Enter the number:"<<endl;
	cin>>n;
	cout<<"Value is: "<<findNth(n)<<endl;
	return 0;
}
