/* Algorithm Name-EgyptianFractions*/
/* Any fraction (numerator/denominator) can be expressed as a sum of positive distinct unit fractions. Unit fractions are fractions with numerator 1.
For example fraction 6/14 can be expressed as 1/3,1/11,1/231.
Procedure to find Egyptian Fraction is if numerator < denominator then first egyptian fraction is "1/quotient" where quotient is equal to Math.ceil(denominatoir/numerator).
The next the Egyptian Fraction will be founded by changing the original fraction (numerator/denominator) to numerator/denominator-1/quotient.
Sample Input 
Enter numerator and denominator 
6
14
Sample Output
1/3
1/11
1/231
*/

#include <iostream>

using namespace std;

int main()
{  int numerator,denominator,quotient;
    cout<<"Enter numerator and denominator";
    cout<<"\n";
    cin>> numerator>>denominator;
     while(numerator>denominator)
        numerator=numerator%denominator;
        while(denominator>numerator && numerator>0 && denominator>0)
        {   
            if(numerator==1)
            {
                cout<<"1/"<<denominator;
                 cout<<"\n";
                break;
            }
            else if(denominator==1)
             break;
            else 
            {
                if(denominator%numerator==0)
                 quotient=denominator/numerator;
                else
                 quotient=denominator/numerator+1;
                
                cout<<"1/"<<quotient;
                cout<<"\n";
                numerator=numerator*quotient-denominator;
                denominator=denominator*quotient;
            }
        }

    return 0;
}
