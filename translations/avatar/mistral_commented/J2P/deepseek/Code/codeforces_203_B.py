import sys

def main():
    # Read the size of the grid and the number of stones to be placed
    N, M = map(int, sys.stdin.readline().split())
    
    # Create a 2D list of size (N+2) x (N+2) to represent the grid
    black = [[0] * (N + 2) for _ in range(N + 2)]
    
    # Iterate M times, once for each stone to be placed
    for m in range(1, M + 1):
        # Read the x-coordinate and y-coordinate of the next stone
        x, y = map(int, sys.stdin.readline().split())
        
        # Iterate over all the neighboring cells in the x-direction
        for xx in range(x - 1, x + 2):
            # Iterate over all the neighboring cells in the y-direction
            for yy in range(y - 1, y + 2):
                # Increment the count of black cells around this cell
                black[xx][yy] += 1
                # Check if the number of black cells around this cell becomes 9
                if black[xx][yy] == 9:
                    # If so, print the index of the stone and return
                    print(m)
                    return
    
    # If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return
    print(-1)

if __name__ == "__main__":
    main()
