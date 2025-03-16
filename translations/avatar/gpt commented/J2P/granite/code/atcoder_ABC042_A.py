
import sys

def main():
    # Read a line of input and split it into an array of strings
    line = sys.stdin.readline().split()

    # Parse the first three elements of the input into integers
    x = int(line[0])
    a = int(line[1])
    y = int(line[2])

    # Initialize a variable to hold the result, defaulting to "NO"
    h = "NO"

    # Check if any of the numbers x, a, or y are either 5 or 7
    if x == 5 or x == 7 or a == 5 or a == 7 or y == 5 or y == 7:
        # If the sum of x, a, and y equals 17, set the result to "YES"
        if x + y + a == 17:
            h = "YES"

    # Output the result
    print(h)

if __name__ == "__main__":
    main()

