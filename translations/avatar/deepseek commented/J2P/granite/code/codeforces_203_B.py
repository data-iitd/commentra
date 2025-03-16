

import sys # Import the sys module for reading input

N, M = map(int, sys.stdin.readline().split()) # Read the first line of input, which contains two integers N and M

# Initialize a 2D array 'black' with dimensions (N+2) x (N+2)
black = [[0] * (N + 2) for _ in range(N + 2)]

# Loop through M operations
for m in range(1, M + 1):
    x, y = map(int, sys.stdin.readline().split()) # Read the current operation's coordinates x and y

    # Increment the elements in the 'black' array within the 3x3 neighborhood of (x, y)
    for xx in range(x - 1, x + 2):
        for yy in range(y - 1, y + 2):
            if black[xx][yy] + 1 == 9: # Increment the element and check if it reaches 9
                print(m) # Print the current operation number
                sys.exit() # Exit the program
    for xx in range(x - 1, x + 2):
        for yy in range(y - 1, y + 2):
            black[xx][yy] += 1 # Increment the element

# If no element reaches 9 after all operations, print -1
print(-1)

