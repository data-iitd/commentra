# Importing required classes for file I/O and input handling
import sys

# Main function starts the execution of the program
def main():
    # Initialize input from standard input
    input = sys.stdin.read
    data = input().split()
    
    # Read input values for H, W, A, and B
    H = int(data[0])  # Height of the grid
    W = int(data[1])  # Width of the grid
    A = int(data[2])  # Number of columns in the first row
    B = int(data[3])  # Number of rows in the last row

    # Check if the grid dimensions meet the conditions
    if W < 2 * A or H < 2 * B:
        print(-1)  # Print -1 if the conditions are not met
        return  # Exit the program

    # Write the grid to the output
    for i in range(H):
        for j in range(W):
            # Write '0' if the current cell is outside the given rectangular region, otherwise write '1'
            if (i < B and j < A) or (i >= B and j >= A):
                print("0", end="")
            else:
                print("1", end="")
        print()  # Move to the next line after writing a row

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
