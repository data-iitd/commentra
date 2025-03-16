#include<stdio.h>
int main():
  int n,l[2001],i,j,k,cnt=0,tmp=0;
  scanf("%d",&n);
  for i in range(0,n):
    scanf("%d",&l[i]);
  for i in range(0,n-1):
    for j in range(i+1,n):
      if l[j]<l[i]:
        tmp=l[i];
        l[i]=l[j];
        l[j]=tmp;
  for i in range(0,n-2):
    for j in range(i+1,n-1):
      for k in range(j+1,n):
        if l[i]+l[j]>l[k]:
          cnt++;
        else:
          break;
  printf("%d\n",cnt);
  return 0;
