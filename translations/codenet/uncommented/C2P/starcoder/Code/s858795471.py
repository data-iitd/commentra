
#include<stdio.h>
def search(A,n,key):
    i=0
    A[n]=key
    while(A[i]!=key):
        i+=1
    return i!=n

n=int(input())
A=[0]*(n+1)
for i in range(n):
    A[i]=int(input())
q=int(input())
sum=0
for i in range(q):
    key=int(input())
    if(search(A,n,key)):
        sum+=1
print(sum)

