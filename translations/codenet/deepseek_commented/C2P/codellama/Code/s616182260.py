#include<stdio.h>
int main():
  a=[0]
  b=[]
  c=[]
  i=0
  j=0
  
  # Read the 3x3 matrix from the input
  for i in range(3):
    scanf("%d%d%d",&c[i][0],&c[i][1],&c[i][2])
  
  # Initialize the first element of array a to 0
  a[0]=0
  
  # Assign the first row of the matrix to array b
  for i in range(3):
    b[i]=c[0][i]
  
  # Calculate the remaining elements of array a
  for i in range(1,3):
    a[i]=c[i][0]-b[0]
  
  # Check if each element of the matrix is equal to the sum of the corresponding elements of a and b
  for i in range(3):
    for j in range(3):
      if c[i][j]!=a[i]+b[j]:
        puts("No")
        return 0
  
  # If all elements match, print "Yes"
  puts("Yes")
  return 0

