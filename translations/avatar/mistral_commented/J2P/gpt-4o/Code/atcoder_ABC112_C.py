import sys  # Importing sys for reading input
from itertools import product  # Importing product for Cartesian product

MAX = 100  # Defining a constant MAX with value 100

def main():
    n = int(sys.stdin.readline().strip())  # Reading the number of elements n from the standard input
    x, y, h = [], [], []  # Creating lists x, y, and h

    for _ in range(n):  # Reading and initializing the arrays
        xi, yi, hi = map(int, sys.stdin.readline().strip().split())
        x.append(xi)
        y.append(yi)
        h.append(hi)

    for i, j in product(range(MAX + 1), repeat=2):  # Iterating through all possible positions (i, j)
        ch = check(n, x, y, h, i, j)  # Calling the check function to calculate the height of the water at position (i, j)
        if ch > 0:  # If the height is greater than 0, print the position and height
            print(f"{i} {j} {ch}")

def check(n, x, y, h, cx, cy):
    ch = -1  # Initializing the height to -1

    for i in range(n):  # Loop to iterate through all elements in the lists x, y, and h
        if h[i] > 0:  # If the height of the current element is greater than 0
            ch = abs(x[i] - cx) + abs(y[i] - cy) + h[i]  # Calculate the distance and height of the current element
            break  # Exit the loop once the closest element is found

    for i in range(n):  # Loop to check if all elements have the same height as the closest one
        if h[i] != max(ch - abs(x[i] - cx) - abs(y[i] - cy), 0):  # If the height is different, return -1 to indicate an error
            return -1

    return ch  # Return the height of the water at position (cx, cy)

if __name__ == "__main__":
    main()  # Start the program

# <END-OF-CODE>
