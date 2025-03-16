import sys

# Read input values for height (h) and width (w)
h, w = map(int, input().split())

# Define the target string to find
s = "snuke"

# Initialize a 2D list to store the input characters
grid = []

# Read the grid input
for _ in range(h):
    row = input().strip()
    grid.append(row)

# Iterate through the grid to find the target string
for i in range(h):
    for j in range(w):
        if grid[i][j:j+len(s)] == s:
            # If the target string is found, print the position in the required format
            print(chr(ord('A') + j) + str(i + 1))
            sys.exit()

# If the target string is not found, you can add an error message or handle it as needed
print("Target not found")
