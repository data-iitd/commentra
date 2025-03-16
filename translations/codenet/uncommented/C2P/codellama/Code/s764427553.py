#include<stdio.h>

int main():
    const int MAX_V=999999
    int prime[MAX_V+1]
    int i,k,n
    for i in range(2,MAX_V+1):
        prime[i]=1
    for i in range(2,MAX_V+1):
        if prime[i]:
            for k in range(2*i,MAX_V+1,i):
                prime[k]=0
    prime[0]=0
    prime[1]=0
    int count=0
    while scanf("%d",&n)!=EOF:
        count++
        int cnt=0
        for i in range(n,0,-1):
            if prime[i]==1:
                cnt++
        printf("%d\n",cnt)
        if count==30:
            break
    return 0
