import sys

# Read the number of cells (n) and the target cell (t) from input
n, t = map(int, input().split())

# Read the list of jumps for each cell
s = list([int(x) for x in input().split()])

# Initialize the current cell position
current_cell = 0

# Loop until the current cell exceeds the target cell
while current_cell <= t:
    # Move to the next cell based on the jump value from the current cell
    current_cell += s[current_cell - 1]
    
    # Check if the current cell is exactly the target cell
    if current_cell == t:
        print("YES")  # Print "YES" if the target cell is reached
        sys.exit()     # Exit the program
    else:
        continue  # Continue the loop if the target cell is not reached

# If the loop ends without reaching the target cell, print "NO"
print("NO")
