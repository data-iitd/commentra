
import sys # Import the standard input/output library

def main(): # Declare the main function with no arguments and no return value
  s = input() # Read a string of length less than or equal to 3 from the standard input and store it in variable s
  t = input() # Read a string of length less than or equal to 3 from the standard input and store it in variable t
  hit = 0 # Initialize a counter variable hit to 0
  for i in range(3): # Start a for loop that iterates from 0 to 2 (3 times)
    if s[i] == t[i]: hit += 1 # If the i-th character of string s is equal to the i-th character of string t, increment the counter variable hit
  print(hit) # Print the value of the counter variable hit to the standard output
  return 0 # Indicate that the main function has terminated successfully with a return value of 0

if __name__ == "__main__": # Check if the script is being run directly (not imported as a module)
  sys.exit(main()) # Call the main function and exit the script with the return value of the main function

