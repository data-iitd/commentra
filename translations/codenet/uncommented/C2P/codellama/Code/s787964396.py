#include<stdio.h>
#include<stdlib.h>
#define I 10000
def CountingSort(a,b,n):
  c=[0]*(I+1)
  for i in range(I+1):
    c[i]=0
  for j in range(n):
    c[a[j+1]]+=1
  for i in range(1,I+1):
    c[i]+=c[i-1]
  for j in range(n,0,-1):
    b[c[a[j]]]=a[j]
    c[a[j]]-=1
#main
n=int(input())
a=[0]*(n+1)
b=[0]*(n+1)
for i in range(n):
  a[i+1]=int(input())
CountingSort(a,b,n)
print(b[1])
for i in range(2,n+1):
  print(b[i],end=" ")
print()
#END-OF-CODE
