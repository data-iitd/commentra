# Step 1: Include the standard input/output library.
import sys

# Step 2: Define the main function.
def main():
    # Step 3: Declare three integer variables: a, b, and s.
    a = 0
    b = 0
    s = 0

    # Step 4: Read two integers from the user input and store them in variables a and b.
    a = int(input())
    b = int(input())

    # Step 5: Calculate the value of s using the formula (a*b) - (a + b) + 1.
    s = (a*b) - (a + b) + 1

    # Step 6: Print the value of s.
    print(s)

# Step 7: Call the main function.
if __name__ == "__main__":
    main()

