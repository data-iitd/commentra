import sys

# Function to read the next line of input and return it as a string
def next_line():
    return sys.stdin.readline().strip()

def main():
    # Read the first integer from input and convert it to an integer
    a = int(next_line())
    # Read the second integer from input and convert it to an integer
    b = int(next_line())

    # Check if the product of a and b is odd
    if a * b % 2 != 0:
        # If the product is odd, print "Odd"
        print("Odd")
    else:
        # If the product is even, print "Even"
        print("Even")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
