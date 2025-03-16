import sys

# Function to read a single line from stdin and return it as an integer
def next_int():
    return int(sys.stdin.readline().strip())

# Main function
def main():
    # Read the first two integers from stdin and store them in variables a and b
    a = next_int()  # Convert the first line read from stdin to an integer and store it in variable a
    b = next_int()  # Convert the second line read from stdin to an integer and store it in variable b

    # Check if the product of a and b is odd or even
    if a * b % 2 != 0:
        # If the product is odd, print "Odd" to stdout
        print("Odd")
    else:
        # If the product is even, print "Even" to stdout
        print("Even")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
