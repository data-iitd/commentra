
import sys

# Main method is the entry point of the Python application
def main():
    # Read the number of integers from the standard input
    n = int(input())

    # Initialize an empty HashMap with Integer keys and Integer values
    map = {}

    # Iterate through the given number of integers and add each integer to the HashMap with its count
    for i in range(n):
        val = int(input()) # Read the next integer from the standard input
        map[val] = map.get(val, 0) + 1 # Add the integer to the HashMap with its count or 1 if it's the first occurrence

    # Initialize minimum value and maximum value variables
    max = -sys.maxsize
    for key, value in map.items():
        # Update the maximum value if the current entry's value is greater than the maximum value
        max = max if max > value else value

    # Print the maximum value and the size of the HashMap
    print(max, len(map))

# Entry point of the program
if __name__ == "__main__":
    main()

# 