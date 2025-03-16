#include<stdio.h>

def linersearch(a,n,key):
  i=0
  a[n]=key
  while(a[i]!=key):
    i+=1
  return i!=n

n=int(input())
s=[0]*n
for i in range(n):
  s[i]=int(input())
q=int(input())
count=0
for i in range(q):
  t=int(input())
  if(linersearch(s,n,t)):
    count+=1
print(count)

