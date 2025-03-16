

import sys

def main():
    # Read a line of input from the user
    line = sys.stdin.readline().strip()

    # Split the input line into an array of strings
    list = line.split(" ")

    # Parse the first three elements of the array as integers
    x = int(list[0])
    a = int(list[1])
    y = int(list[2])

    # Initialize a variable to store the result
    h = "NO"

    # Check if any of the integers is either 5 or 7
    if x == 5 or x == 7 or a == 5 or a == 7 or y == 5 or y == 7:
        # Check if the sum of the integers is 17
        if x + y + a == 17:
            h = "YES"

    # Print the result
    print(h)

if __name__ == "__main__":
    main()

