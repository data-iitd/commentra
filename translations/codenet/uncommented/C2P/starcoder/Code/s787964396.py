#include<stdio.h>
#include<stdlib.h>
#define I 10000
def CountingSort(a,b,k):
  c=[0]*I
  for i in range(0,k):
    c[a[i+1]]+=1
  for i in range(1,I+1):
    c[i]+=c[i-1]
  for j in range(k,0,-1):
    b[c[a[j]]]=a[j]
    c[a[j]]-=1
n=int(input())
a=[0]*(n+1)
b=[0]*(n+1)
for i in range(0,n):
  a[i+1]=int(input())
CountingSort(a,b,n)
print(b[1],end=' ')
for i in range(2,n+1):
  print(b[i],end=' ')
print()
