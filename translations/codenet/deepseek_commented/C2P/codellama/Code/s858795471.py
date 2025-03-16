#include<stdio.h>
def search(A,n,key):
    i=0
    # Add the key to the end of the array to handle the case where the key is not found
    A.append(key)
    # Loop until the key is found in the array
    while A[i]!=key: i+=1
    # Return 1 if the key is found, otherwise return 0
    return i!=n

n=int(input())
A=list(map(int,input().split()))
q=int(input())
key=int(input())
sum=0
for i in range(q):
    key=int(input())
    if search(A,n,key): sum+=1
print(sum)

