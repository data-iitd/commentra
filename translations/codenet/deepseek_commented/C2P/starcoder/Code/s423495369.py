# Step 1: Include the standard input/output library to use printf and scanf functions.
import sys

# Step 2: Define the main function where the execution of the program begins.
def main():
  # Step 3: Declare three integer variables A, B, and C.
  A = int(input())
  B = int(input())
  C = int(input())

  # Step 4: Use scanf function to read three integers from the user and store them in variables A, B, and C.

  # Step 5: Check if the value of C is between A and B using if-else statements.
  if (A < C and C < B):
    # Print "Yes" if the condition is true.
    print("Yes")
  elif (A > C and C > B):
    # Print "Yes" if the condition is true.
    print("Yes")
  else:
    # Print "No" if the condition is false.
    print("No")

# Step 6: Call the main function to execute the program.
if __name__ == "__main__":
  main()

