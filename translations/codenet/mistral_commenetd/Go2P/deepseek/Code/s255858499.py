import sys

# Function to read a single line from stdin and return it as a string
def next_line():
    # Read the next line from stdin
    return sys.stdin.readline().strip()

# Main function
def main():
    # Read the first two integers from stdin and store them in variables a and b
    a = int(next_line())  # Convert the first line read from stdin to an integer and store it in variable a
    b = int(next_line())  # Convert the second line read from stdin to an integer and store it in variable b

    # Check if the product of a and b is odd or even
    if a * b % 2 != 0:
        # If the product is odd, print "Odd" to stdout
        print("Odd")
    else:
        # If the product is even, print "Even" to stdout
        print("Even")

# Call the main function
if __name__ == "__main__":
    main()

