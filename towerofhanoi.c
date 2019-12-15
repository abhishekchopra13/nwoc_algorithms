#include<stdio.h>
void TowerOfHanoi(int SIZE, char c1, char c2, char c3)
{
    if(SIZE==1)
    {
        printf("%d  Disc  transferred from %c to %c \n", SIZE, c1, c3);
    }
    else{
        TowerOfHanoi(SIZE-1,c1,c3,c2);
        printf("%d Transfer Disc From %c TO %c\n",SIZE,c1,c3);
        TowerOfHanoi(SIZE-1,c2,c1,c3);
    }
}
void main()
{
    TowerOfHanoi(3,'s','m','d');
}
