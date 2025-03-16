# Import the sys module for reading input
import sys

def main():
    # Read the values of x1, y1, x2, and y2 from the standard input
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())

    # Calculate the differences between the x and y coordinates of the second point and the first point
    a = x2 - x1
    b = y2 - y1

    # Calculate the new x and y coordinates of the first point and the second point based on the values of a and b
    x3 = x2 - b
    y3 = y2 + a
    x4 = x1 - b
    y4 = y1 + a

    # Print the new x and y coordinates of the first and second points
    print(x3, y3, x4, y4)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
