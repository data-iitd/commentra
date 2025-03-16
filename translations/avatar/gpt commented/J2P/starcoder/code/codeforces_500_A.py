
# Depth-first search (DFS) method to determine if the target can be reached
def dfs(currpos, arr, target):
    # Base case: if the current position equals the target, return true
    if currpos == target:
        return True
    
    # Base case: if the current position exceeds the bounds of the array, return false
    if currpos == len(arr) + 1:
        return False
    
    # Recursive case: attempt to teleport to the next position based on the current array value
    teleport = dfs(currpos + arr[currpos - 1], arr, target)
    
    # If teleporting leads to the target, return true
    if teleport:
        return True
    
    # If no valid path found, return false
    return False

# Create a Scanner object for input
import sys

n = int(sys.stdin.readline())
goal = int(sys.stdin.readline())

# Initialize an array to hold the teleportation values
arr = []

# Populate the array with teleportation values from input
for i in range(n - 1):
    arr.append(int(sys.stdin.readline()))

# Call the DFS function starting from position 1 to check if the goal can be reached
isFound = dfs(1, arr, goal)

# Output the result based on whether the goal was found
if isFound:
    print("YES")
else:
    print("NO")

# 