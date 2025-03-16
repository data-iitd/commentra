
#include<stdio.h>
def linersearch(a,n,key):
  i=0
  a[n]=key
  while(a[i]!=key):
    i+=1
  return i!=n

n=int(input())
a=[0]*(n+1)
for i in range(n):
  a[i]=int(input())
q=int(input())
count=0
for i in range(q):
  t=int(input())
  if(linersearch(a,n,t)):
    count+=1
print(count)

