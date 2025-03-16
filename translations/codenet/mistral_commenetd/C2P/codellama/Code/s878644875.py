#include <stdio.h> # Include the standard input/output library

int main(void): # Declare the main function with no arguments and no return value
  s = [0] * 4 # Declare two character arrays of size 4
  t = [0] * 4
  scanf("%s", s) # Read a string of length less than or equal to 3 from the standard input and store it in array s
  scanf("%s", t) # Read a string of length less than or equal to 3 from the standard input and store it in array t
  hit = 0 # Initialize a counter variable hit to 0
  for i in range(0, 3): # Start a for loop that iterates from 0 to 2 (3 times)
    if s[i] == t[i]: hit += 1 # If the i-th character of string s is equal to the i-th character of string t, increment the counter variable hit
  print(hit) # Print the value of the counter variable hit to the standard output followed by a newline character
  return 0 # Indicate that the main function has terminated successfully with a return value of 0

