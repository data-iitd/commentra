#include <iostream> // Include the iostream library for input/output operations
using namespace std; // Use the standard namespace for easier access to iostream functions

int main()  { // Start of the main function
  int A, B, C, X; // Declare variables A, B, C, and X to store user input
  cin >> A >> B >> C >> X; // Read user input for variables A, B, C, and X using cin

  int cnt = 0; // Initialize counter variable cnt to 0
  for a in range(0, A+1): # Start of the outermost for loop, iterating from 0 to A
    for b in range(0, B+1): # Start of the inner for loop, iterating from 0 to B
      for c in range(0, C+1): # Start of the innermost for loop, iterating from 0 to C
        total = 500*a + 100*b + 50*c # Calculate the total value based on the current values of a, b, and c
        if total == X: cnt += 1 # If the total value equals X, increment the counter variable cnt
  print(cnt) # Output the final value of the counter variable cnt to the console
}


