#include<stdio.h>
int main()
{
    int n;
    // Read an integer from the user
    scanf("%d",&n);
    
    // Check if n is divisible by 1000
    if(n%1000==0) 
        // If n is divisible by 1000, print 0
        printf("%d\n",0);
    else 
        // If n is not divisible by 1000, calculate the difference
        // between the next multiple of 1000 and n, and print that difference
        printf("%d\n",(n/1000+1)*1000-n);
}
