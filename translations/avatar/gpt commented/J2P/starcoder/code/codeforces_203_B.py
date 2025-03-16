import sys; # Import the sys module to read input from the user

def main():
    # Read the dimensions of the grid (N) and the number of moves (M)
    N = int(sys.stdin.readline())
    M = int(sys.stdin.readline())
    
    # Initialize a 2D array to keep track of the black cells, with padding to avoid boundary checks
    black = [[0 for i in range(N + 2)] for j in range(N + 2)]
    
    # Loop through each move
    for m in range(1, M + 1):
        # Read the coordinates of the current move
        x, y = map(int, sys.stdin.readline().split())
        
        # Increment the count of black cells in the surrounding 3x3 area
        for xx in range(x - 1, x + 2):
            for yy in range(y - 1, y + 2):
                # Increment the count for the current cell
                black[xx][yy] += 1
                
                # Check if the count reaches 9
                if black[xx][yy] == 9:
                    print(m) # Print the move number where the condition is met
                    return # Exit the program
    
    # If no cell reached the count of 9 after all moves, print -1
    print(-1)

if __name__ == "__main__":
    main()

