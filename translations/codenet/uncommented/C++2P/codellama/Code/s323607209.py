#include <stdio.h>
int main():
    int n,k
    long long int l=0,r=0
    scanf("%d%d",&n,&k)
    if k%2==0:
        for i in range(1,n+1):
            if i%k==k/2:
                l+=1
            else:
                if i%k==0:
                    r+=1
    else:
        for i in range(1,n+1):
            if i%k==0:
                r+=1
    print(l*l*l+r*r*r)

