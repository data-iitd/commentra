#include<stdio.h>
int main():
  a=[0]
  b=[0,0,0]
  c=[[0,0,0],[0,0,0],[0,0,0]]
  i=0
  j=0
  for i in range(3):
    scanf("%d%d%d",&c[i][0],&c[i][1],&c[i][2])
  for i in range(3):
    b[i]=c[0][i]
  for i in range(3):
    a[i]=c[i][0]-b[0]
  for i in range(3):
    for j in range(3):
      if c[i][j]!=a[i]+b[j]:
        puts("No")
        return 0
  puts("Yes")
  return 0
