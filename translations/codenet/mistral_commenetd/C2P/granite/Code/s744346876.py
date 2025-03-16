
import sys # Import the standard input/output library

def main(): # Define the main function
  A, B = map(int, sys.stdin.readline().split()) # Read two integers from the standard input and store them in variables A and B
  if A < 10 and B < 10: # Check if both A and B are less than 10
    print(A * B) # If true, print the product of A and B to the standard output
  else: # If the condition is false
    print(-1) # Print -1 to the standard output as an error message

if __name__ == "__main__": # Call the main function if the script is run directly
  main() # Run the main function

