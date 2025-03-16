#include<stdio.h>
def main():
  n=int(input())
  l=[int(x) for x in input().split()]
  for i in range(n-1):
    for j in range(i+1,n):
      if(l[j]<l[i]):
        tmp=l[i]
        l[i]=l[j]
        l[j]=tmp
  cnt=0
  for i in range(n-2):
    for j in range(i+1,n-1):
      for k in range(j+1,n):
        if(l[i]+l[j]>l[k]):
          cnt+=1
        else:
          break
  print(cnt)

