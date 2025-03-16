#include<stdio.h>

int main(void):
    int n,i,a

    scanf("%d",&n)

    for i in range(1,n+1):
        a=i

        if(a%3==0):
            print(" %d"%i)
        else:
            while a!=0:
                if(a%10==3):
                    print(" %d"%i)
                    a=0
                a=a//10

    print()
    return 0

