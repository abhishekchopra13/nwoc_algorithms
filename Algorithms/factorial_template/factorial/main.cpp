#include <iostream>

using namespace std;

int main()
{   //FACTORIAL
    //no of which factorial s to be found out,
    int n;
    cin>>n;

// We can also do this without the array, using the for loop only also
    int arr[n];
    long long int fac = 1;

    for(int i=1; i<=n; i++){
    fac= fac*(i);
    arr[i-1] = fac;
}
if(n==0){
    arr[n-1] = 1;
    }
//An array of all the numbers till then would be created.
//To access the factorial of the number
cout<<arr[n-1];
return 0;
     }

