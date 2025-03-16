import sys

# Function to read the next line of input and return it as a string
def next():
    return sys.stdin.readline().strip()  # Read a line from standard input and strip whitespace

# Function to read the next line of input, convert it to an integer, and return it
def next_int():
    return int(next())  # Convert the scanned text to an integer and return it

def main():
    # Read two integers, sum them, and compare the result with a third integer
    if next_int() + next_int() >= next_int():
        print("Yes")  # Print "Yes" if the sum is greater than or equal to the third integer
    else:
        print("No")  # Print "No" otherwise

if __name__ == "__main__":
    main()

# <END-OF-CODE>
