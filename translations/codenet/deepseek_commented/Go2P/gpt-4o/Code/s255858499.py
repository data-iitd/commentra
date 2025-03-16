import sys

# Function to read the next line of input from the user
def next_line():
    return sys.stdin.readline().strip()

def main():
    # Reading the first integer input
    a = int(next_line())
    # Reading the second integer input
    b = int(next_line())

    # Checking if the product of a and b is odd or even and printing the result
    if (a * b) % 2 != 0:
        print("Odd")
    else:
        print("Even")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
