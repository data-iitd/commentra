

import sys # Import sys module for reading input from standard input

def main():
    n = int(input()) # Read the number of integers from the standard input

    # Initialize an empty dictionary with Integer keys and Integer values
    d = {}

    # Iterate through the given number of integers and add each integer to the dictionary with its count
    for _ in range(n):
        val = int(input()) # Read the next integer from the standard input
        d[val] = d.get(val, 0) + 1 # Add the integer to the dictionary with its count or 1 if it's the first occurrence

    # Initialize minimum value and maximum value variables
    max_val = float('-inf') # Initialize maximum value to negative infinity
    for key, value in d.items():
        # Update the maximum value if the current entry's value is greater than the maximum value
        max_val = max(max_val, value)

    # Print the maximum value and the size of the dictionary
    print(max_val, len(d))

if __name__ == "__main__":
    main()

These comments should provide a clear understanding of the code's functionality and logic.