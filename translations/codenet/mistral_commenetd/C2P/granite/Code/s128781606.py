
import sys # Import the standard input/output library

def main(): # The entry point of the program
  A, B = map(int, sys.stdin.readline().split()) # Read two integers from the standard input and store them in variables A and B

  C = A + B # Compute the sum of A and B and store the result in variable C

  D = A - B # Compute the difference of A and B and store the result in variable D

  E = A * B # Compute the product of A and B and store the result in variable E

  max = C # Initialize max with the value of C

  if max < D: # Check if D is greater than max
    max = D # If so, update max with the value of D

  if max < E: # Check if E is greater than max
    max = E # If so, update max with the value of E

  print(max) # Print the maximum value to the standard output

if __name__ == "__main__": # Call the main function if the script is executed directly
  main() # Call the main function

