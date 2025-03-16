#include<stdio.h>
int main():
  char m
  int a,b,c[256],i,j
  for i in range(0,256):
    scanf("%d %c %d",&a,&m,&b)
    if m=='?':
      break
    if m=='+':
      c[i]=a+b
    if m=='-':
      c[i]=a-b
    if m=='*':
      c[i]=a*b
    if m=='/':
      c[i]=a/b
  for j in range(0,i):
    printf("%d\n",c[j])
  return(0)
