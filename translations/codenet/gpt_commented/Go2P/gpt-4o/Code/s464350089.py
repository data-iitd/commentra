import sys

# Define a constant for the modulo value
mod = 1000000007

# Function to read the next integer from input
def next_int():
    return int(sys.stdin.readline().strip())

def main():
    # Read the values of h and n from input
    h = next_int()
    n = next_int()
    a = 0  # Initialize a variable to accumulate the sum of integers

    # Loop to read n integers and accumulate their sum
    for _ in range(n):
        a += next_int()

    # Check if the accumulated sum is less than h
    if h > a:
        # If h is greater than the sum, print "No"
        print("No")
    else:
        # Otherwise, print "Yes"
        print("Yes")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
