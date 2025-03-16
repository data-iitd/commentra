def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    # Read the first integer input, which is the size of the grid
    N = int(data[0])
    # Read the second integer input, which is the number of operations
    M = int(data[1])
    
    # Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
    black = [[0] * (N + 2) for _ in range(N + 2)]
    
    # Loop through M operations
    for m in range(2, M + 2):
        x = int(data[m])
        y = int(data[m + 1])
        m += 2
        
        # Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
        for xx in range(x - 1, x + 2):
            for yy in range(y - 1, y + 2):
                black[xx][yy] += 1
                if black[xx][yy] == 9:
                    print(m)
                    return
    
    # If no element reaches 9 after all operations, print -1
    print(-1)

if __name__ == "__main__":
    main()
