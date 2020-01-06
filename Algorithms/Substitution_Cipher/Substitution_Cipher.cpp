#include <bits/stdc++.h>

int main()
{
	char msg[100],ch[5];
	int step=0;
	int i,len=0;
	std::cout<<"Enter encrypted message: ";
	std::cin>>msg;
	std::cout<<"Enter \"CLUE\": ";
	std::cin>>ch;
	step = (-1) * ((ch[0])-'C');
	len = strlen(msg);
	std::cout<<"Decoded message is .....\n";
    for(i=0;i<len;i++)
    {
    	if(msg[i]==' ')
    	{
    		std::cout<<msg[i];
    		continue;
		}
		if((ch[0]-'C')>=0)   //Right Shift
        {
            if((char(msg[i]+step) >= 'A') && (char(msg[i]+step) <='Z'))
            std::cout<<char(msg[i]+step);
    	else if(char(msg[i]+step) >'Z')
            std::cout<<char(msg[i]+step-'Z'+'A'-1);
        else if(char(msg[i]+step) <'A')
            std::cout<<char('Z'-('A'-msg[i]-step) + 1);
		}
		else   //Left Shift
		{
            if((char(msg[i]-step) >= 'A') && (char(msg[i]-step) <='Z'))
            std::cout<<char(msg[i]-step);
    	else if(char(msg[i]-step) >'Z')
            std::cout<<char(msg[i]-step-'Z'+'A'-1);
        else if(char(msg[i]-step) <'A')
            std::cout<<char('Z'-('A'-msg[i]+step) + 1);
		}

	}
}
