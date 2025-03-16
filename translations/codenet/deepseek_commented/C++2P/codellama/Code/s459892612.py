#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  # Declare three integer variables to store user input
  a, b, c = 0, 0, 0
  
  # Read three integers from the standard input
  a, b, c = input("Enter three integers: ").split()

  # Check if the sum of a and b is greater than or equal to c
  if (a + b >= c):
    # If true, print "Yes"
    print("Yes")
  else:
    # Otherwise, print "No"
    print("No")
  
  # Return 0 to indicate successful execution
  return 0
}

