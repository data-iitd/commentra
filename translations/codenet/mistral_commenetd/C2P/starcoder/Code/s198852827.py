
#include<stdio.h>

#define ABS(x) (((x)<(0))?(-(x)):(x)) # Macro to calculate the absolute value of a number

def main():
  N = int(input()) # Variable to store the number of test cases
  t,x,y,nx=0,ny=0,nt=0 # Variables to store the current test case data and previous coordinates
  i,j,k,tmp # Loop variables

  for i in range(N): # Loop through each test case
    t,x,y = map(int,input().split()) # Read the current test case data (t, x, y)
    tmp = t-nt-(ABS(x-nx)+ABS(y-ny)) # Calculate the temporary variable 'tmp' to check the distance between the current and previous coordinates
    if(tmp<0 or tmp%2): # Check if the current test case satisfies the condition
      print("No") # If the condition is not satisfied, print 'No' and exit the program
      return 0
    nx=x # Update the previous coordinates for the next iteration
    ny=y
    nt=t
  print("Yes") # If all the test cases satisfy the condition, print 'Yes'

if __name__ == "__main__":
  main()

