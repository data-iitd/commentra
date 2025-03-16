

import sys # Importing the sys module

# Main function where the execution of the program starts
def main():

  # Reading the first integer input N
  N = int(sys.stdin.readline())

  # Initializing the minimum integer variable with the first input value
  min = 0
  for i in range(5):
    if i == 0: # If it's the first iteration of the loop
      min = int(sys.stdin.readline()) # Set the minimum value to the current input value
    else: # Otherwise
      min = min(min, int(sys.stdin.readline())) # Update the minimum value with the current input value if it's smaller

  # Printing the answer using the print function
  print(str((N+min-1)//min+4))

# Executing the main function
if __name__ == "__main__":
  main()

