
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

// Function to find the number of digits in a given number
def digit(n):
  res=0; # Initialize result
  while(n>0): # While number is not zero
    res+=1; # Increment result by 1
    n/=10; # Divide number by 10 to get next digit
  return res; # Return the result

# Function to run the program
def run():
  n=int(input()); # Read number from standard input
  min=digit(n); # Initialize minimum with the number of digits in the number
  for i in range(1,int(math.sqrt(n))+1): # Loop from 1 to square root of the number
    if(n%i!=0): continue; # If current number is not a factor of the given number, skip to next iteration
    a=i; # Initialize first factor
    b=n/i; # Initialize second factor
    min=min(min,max(digit(a),digit(b))); # Update minimum with the maximum of digits in first and second factors
  print(min); # Print the minimum number of digits in any factor of the given number

# Main function
if __name__=='__main__':
  run(); # Call run function to execute the program

