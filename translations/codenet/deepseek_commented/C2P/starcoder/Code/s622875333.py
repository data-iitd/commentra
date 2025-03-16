
#include<stdio.h>

n,r,i,j,p,c=0,0,0,0,0,0
a=[0]*100
b=[0]*100

while(1):
  # Read the values of n and r
  n,r=map(int,input().split())
  # Break the loop if both n and r are zero
  if(n==0 and r==0):break

  # Initialize array a with values from n down to 1
  for i in range(n):
    a[i]=n-i

  # For each round of r
  for i in range(r):
    # Copy array a to array b
    for j in range(n):
      b[j]=a[j]
    # Read the values of p and c
    p,c=map(int,input().split())

    # Perform the shift operation on array a
    for j in range(c):
      a[j]=b[p-1+j]

    # Fill the remaining positions in array a
    for j in range(c,c+p-1):
      a[j]=b[j-c]

  # Print the first element of array a
  print(a[0])

