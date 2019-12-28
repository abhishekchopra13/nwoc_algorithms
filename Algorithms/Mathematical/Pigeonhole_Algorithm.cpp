//PigeonHole is a sorting algorithm that is suitable for sorting lists of element
//where the number of possible key values are approximately the same
#include<bits/stdc++.h>
using namespace std;
void pigeonholeSort(int *arr,int n)
{
	int min=arr[0], max=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]<min)
		min=arr[i];
		if(arr[i]>max)
		max=arr[i];
	}
	int range = max-min+1;
	vector<int> holes[range];
	for(int i=0;i<n;i++)
	{
		holes[arr[i]-min].push_back(arr[i]);
	}
	int index=0;
	for(int i=0;i<range;i++)
	{
		vector<int>::iterator it;
		for(it=holes[i].begin();it!=holes[i].end();++it)
		{
			arr[index++]=*it;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cout<<"Enter the total number which are present in the array:"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the element in the array:"<<endl;
	for(int i=0;i<n;i++)  cin>>arr[i];
	pigeonholeSort(arr,n);
	cout<<"Sorted Array is:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
