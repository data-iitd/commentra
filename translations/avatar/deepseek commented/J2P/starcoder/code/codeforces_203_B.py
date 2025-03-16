
import sys; # Import the sys module for reading input

def main():
    N = int(sys.stdin.readline()); # Read the first integer input, which is the size of the grid
    M = int(sys.stdin.readline()); # Read the second integer input, which is the number of operations

    # Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
    black = [[0 for i in range(N + 2)] for j in range(N + 2)];

    # Loop through M operations
    for m in range(1, M + 1):
        x, y = map(int, sys.stdin.readline().split()); # Read the x-coordinate and y-coordinate of the current operation

        # Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
        for xx in range(x - 1, x + 2):
            for yy in range(y - 1, y + 2):
                black[xx][yy] += 1; # Increment the element

                if black[xx][yy] == 9: # Check if the element reaches 9
                    print(m); # Print the current operation number
                    return; # Exit the program

    # If no element reaches 9 after all operations, print -1
    print(-1);

if __name__ == "__main__":
    main();

