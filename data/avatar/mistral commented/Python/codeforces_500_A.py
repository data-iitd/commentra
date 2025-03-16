# Importing the sys and taking input for number of test cases and time limit
import sys

# Taking input for number of test cases and time limit
n, t = map(int, input().split())

# Initializing an empty list to store the jumps
s = list([int(x) for x in input().split()])

# Initializing the current cell position to 0
current_cell = 0

# Main logic of the program starts here
while current_cell <= t:
    # Incrementing the current cell position by the jump from the previous cell
    current_cell += s[current_cell - 1]

    # Checking if the current cell position is equal to the target position
    if current_cell == t:
        # If yes, then print "YES" and exit the program
        print("YES")
        sys.exit()

    # If not, then continue to the next iteration
    else:
        continue

# If the loop terminates without finding the target position, then print "NO"
print("NO")