#include<iostream>
using namespace std;
int top=-1,size=10;
int main()
{
    int A[10],a;
    char ch='y';
    while(ch!='n'||ch!='N')
    {
        cout<<"1. Push ";
        cout<<"\n2. Pop ";
        cout<<"\n3. Display Last Element \nEnter Choice : ";
        cin>>a;
        if(a==1)
        {
        	cout<<"Enter Element : "<<endl;
            if(top!=size-1)
            {
                cin>>A[++top];
            }
            else
	    {
                cout<<"Stack FULL"<<endl;
	    }
        }
        else if(a==2)
        {
            cout<<"Poped Element : ";
            if(top!=-1)
            {
                cout<<A[top--]<<endl;
            }
            else
	    {
                cout<<"Stack EMPTY";
	    }
        }
        else
	{    
	    if(top!=-1)
	    {
		    cout<<A[top]<<endl;
	    }
	    else
	    {
		cout<<"EMPTY "<<endl;
	    }
    	}
        cout<<"Wanna Continue (Y/N) : ";
        cin>>ch;
    }
}
