# Step 1: Import the sys module for input (optional, can use input() directly).
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Declare three integer variables: a, b, and s.
    a, b = map(int, input().split())  # Step 4: Read two integers from the user input and store them in variables a and b.

    # Step 5: Calculate the value of s using the formula (a*b) - (a + b) + 1.
    s = (a * b) - (a + b) + 1

    # Step 6: Print the value of s.
    print(s)

# Call the main function to execute the code.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
