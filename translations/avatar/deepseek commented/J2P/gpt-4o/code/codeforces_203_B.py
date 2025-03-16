# Import the sys module for reading input
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the first integer input, which is the size of the grid
    M = int(data[1])  # Read the second integer input, which is the number of operations

    # Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
    black = [[0] * (N + 2) for _ in range(N + 2)]

    # Loop through M operations
    index = 2
    for m in range(1, M + 1):
        x = int(data[index])  # Read the x-coordinate of the current operation
        y = int(data[index + 1])  # Read the y-coordinate of the current operation
        index += 2

        # Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
        for xx in range(x - 1, x + 2):
            for yy in range(y - 1, y + 2):
                if (black[xx][yy] := black[xx][yy] + 1) == 9:  # Increment the element and check if it reaches 9
                    print(m)  # Print the current operation number
                    return  # Exit the program

    # If no element reaches 9 after all operations, print -1
    print("-1")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
