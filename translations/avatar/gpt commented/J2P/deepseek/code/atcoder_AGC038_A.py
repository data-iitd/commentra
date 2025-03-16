import sys

def main():
    # Read the dimensions of the grid and the parameters A and B
    H, W, A, B = map(int, sys.stdin.readline().split())
    
    # Check if the grid can accommodate the required number of 0s and 1s
    if W < 2 * A or H < 2 * B:
        print(-1)  # Print -1 if the grid is too small
        return
    
    # Generate the grid based on the parameters A and B
    for i in range(H):  # Iterate over each row
        for j in range(W):  # Iterate over each column
            # Determine whether to write '0' or '1' based on the current position
            if (i < B and j < A) or (i >= B and j >= A):
                sys.stdout.write('0')  # Write '0' for specified conditions
            else:
                sys.stdout.write('1')  # Write '1' otherwise
        sys.stdout.write('\n')  # Move to the next line after finishing a row

if __name__ == "__main__":
    main()
