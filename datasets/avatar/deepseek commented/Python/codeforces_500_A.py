
import sys

# Read the number of cells (n) and the target cell (t)
n, t = map(int, input().split())

# Read the list of cells that can be jumped from each cell
s = list([int(x) for x in input().split()])

# Initialize the current cell to 0
current_cell = 0

# Loop until the current cell exceeds the target cell
while current_cell <= t:
    # Update the current cell by adding the value of the cell it's currently on
    current_cell += s[current_cell - 1]
    
    # Check if the current cell is the target cell
    if current_cell == t:
        # If yes, print "YES" and exit the program
        print("YES")
        sys.exit()
    else:
        # If not, continue to the next iteration
        continue

# If the loop finishes without finding the target cell, print "NO"
print("NO")

