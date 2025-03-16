
#include <stdio.h> // Include the standard input/output header

int main(void){ // Define the main function
  int A, B; // Declare two integer variables A and B
  A = int(input("A = ")) # Read an integer from the user and store it in A
  B = int(input("B = ")) # Read an integer from the user and store it in B
  if(A < 10 and B < 10): # Check if both A and B are less than 10, if true
    print(A * B) # Print the multiplication result
  else:
    print(-1) # If the condition is false, print -1
  return 0 # Return 0 to indicate successful execution
}


