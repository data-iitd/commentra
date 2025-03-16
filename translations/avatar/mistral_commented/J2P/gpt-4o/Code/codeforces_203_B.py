# Import the sys module for reading input
import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])  # Read the first integer from the input, which represents the size of the grid
    M = int(data[1])  # Read the second integer from the input, which represents the number of stones to be placed
    
    black = [[0] * (N + 2) for _ in range(N + 2)]  # Create a 2D array of size (N+2) x (N+2) to represent the grid
    
    index = 2  # Start reading stones from the third element in data
    for m in range(1, M + 1):  # Iterate M times, once for each stone to be placed
        x = int(data[index])  # Read the x-coordinate of the next stone to be placed
        y = int(data[index + 1])  # Read the y-coordinate of the next stone to be placed
        index += 2
        
        for xx in range(x - 1, x + 2):  # Iterate over all the neighboring cells in the x-direction
            for yy in range(y - 1, y + 2):  # Iterate over all the neighboring cells in the y-direction
                if (black[xx][yy] := black[xx][yy] + 1) == 9:  # Check if the number of black cells around this cell becomes 9
                    print(m)  # If so, print the index of the stone that caused this condition and return
                    return
    
    print("-1")  # If we finish iterating over all the stones without finding one that has 9 black neighbors, print -1 and return

if __name__ == "__main__":
    main()

# <END-OF-CODE>
