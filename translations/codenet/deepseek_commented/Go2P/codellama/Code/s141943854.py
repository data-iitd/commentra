
# Import modules
import sys

# Check for errors
def check(e):
    if e != None:
        print("error:", e)

# Main function
def main():
    # Read input from standard input
    sage = sys.stdin.readline()

    # Switch on input
    if sage == "1\n":
        print("Hello World") # Print "Hello World" if input is "1"
    elif sage == "2\n":
        sum = 0 # Declare sum variable to store the sum of two integers
        for i in range(2):
            # Read input from standard input
            num = int(sys.stdin.readline())
            # Add the integer to the sum
            sum += num
        print(sum) # Print the sum of the two integers

# Call main function
main()

