# Step 1: Import the sys module to use input and output functions.
import sys

# Step 2: Define the main function where the execution of the program begins.
def main():
    # Step 3: Read three integers from the user and store them in variables A, B, and C.
    A, B, C = map(int, input().split())

    # Step 4: Check if the value of C is between A and B using if-else statements.
    if (A < C < B) or (A > C > B):  # Check both conditions in a single if statement.
        print("Yes")  # Print "Yes" if the condition is true.
    else:
        print("No")  # Print "No" if the condition is false.

# Step 5: Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
