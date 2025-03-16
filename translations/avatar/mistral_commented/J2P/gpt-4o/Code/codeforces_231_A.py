# Import the sys module for reading input
import sys

def main():
    # Read the number of test cases from the standard input
    t = int(sys.stdin.readline().strip())
    
    # Initialize a counter variable to keep track of the number of valid cases
    count = 0

    # Process each test case
    for _ in range(t):
        a, b, c = map(int, sys.stdin.readline().strip().split())  # Read three integers from the input

        # Check if any of the given integers are equal to 1. If so, increment the counter.
        if (a == 1 and b == 1) or (a == 1 and c == 1) or (b == 1 and c == 1) or (a == 1 and b == 1 and c == 1):
            count += 1  # Increment the counter if any of the given integers are equal to 1

    # Print the value of the counter to the standard output
    print(count)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
