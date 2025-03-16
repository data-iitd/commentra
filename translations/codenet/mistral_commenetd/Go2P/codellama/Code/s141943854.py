
# Import the necessary modules
import sys

# Function to check for errors and exit with error message if any
def check(e):
    if e:
        print("error:", e)
        sys.exit(1)

# Main function
def main():
    # Initialize a variable named 'sage' to store the first line read from standard input
    sage = sys.stdin.readline().strip()

    # Use a switch statement to determine the action based on the first line read
    if sage == "1":
        # Print "Hello World" if the first line is "1"
        print("Hello World")
    elif sage == "2":
        # Initialize a variable named 'sum' to store the sum of two numbers
        sum = 0

        # Use a for loop to read and sum two numbers
        for i in range(2):
            # Read the next line from standard input
            line = sys.stdin.readline().strip()

            # Convert the next line to an integer and store it in a variable named 'num'
            num = int(line)

            # Add the current number to the sum
            sum += num

        # Print the sum of the two numbers
        print(sum)

# Call the main function
main()

# End of code