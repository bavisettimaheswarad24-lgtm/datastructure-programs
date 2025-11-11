#include<stdio.h>
void tower_of_hanoi(int n,char src,char helper,char dest)
{
    if(n==1)
    {
    printf("\n move disk from %c to %c\n",src,dest);
   return ;
    }


tower_of_hanoi(n-1, src,   dest, helper);
printf("\n move the disk %d from %c to %c ",n,src,dest);
tower_of_hanoi(n-1,   helper,   src,  dest);
}

int main()
{
    int n;
    printf("enter the n value");
    scanf("%d",&n);
    printf("the seq of the moves involved are:");
    tower_of_hanoi(n,"A","B","D");
    return 0;
}
