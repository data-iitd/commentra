import sys

# Utility function to check for errors and exit the program if an error is encountered.
def check(e):
    if e is not None:
        print(f"error: {e}", file=sys.stderr)
        sys.exit(1)

def main():
    # Read the first line of input.
    sage = input().strip()  # Store the input in the variable 'sage'.

    # Use a conditional statement to handle different cases based on the input value.
    if sage == "1":
        # If the input is "1", print "Hello World".
        print("Hello World")
    elif sage == "2":
        # If the input is "2", initialize a variable to hold the sum of two numbers.
        total_sum = 0
        # Loop to read two numbers from input.
        for _ in range(2):
            try:
                num = int(input().strip())  # Convert the input string to an integer.
                total_sum += num  # Add the number to the sum.
            except ValueError as e:
                check(e)  # Check for any conversion errors.
        # Print the total sum of the two numbers.
        print(total_sum)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
