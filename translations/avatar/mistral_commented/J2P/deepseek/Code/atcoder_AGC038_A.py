# Importing required classes for file I/O and Scanner
import sys

# Main method starts the execution of the program
def main():
    # Initialize Scanner for user input
    sc = sys.stdin
    # Initialize BufferedWriter for output
    bw = sys.stdout.write

    # Read input values for H, W, A, and B
    H = int(next(sc).strip())
    W = int(next(sc).strip())
    A = int(next(sc).strip())
    B = int(next(sc).strip())

    # Check if the grid dimensions meet the conditions
    if W < 2 * A or H < 2 * B:
        print(-1)  # Print -1 if the conditions are not met
        return  # Exit the program

    # Write the grid to the output
    for i in range(H):
        for j in range(W):
            # Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if (i < B and j < A) or (i >= B and j >= A):
                bw('0')
            else:
                bw('1')
        bw('\n')  # Move to the next line after writing a row

# Call the main method
if __name__ == "__main__":
    main()
