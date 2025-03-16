def dfs(currpos, arr, target):
    # Base case: if the current position equals the target, return True
    if currpos == target:
        return True
    
    # Base case: if the current position exceeds the bounds of the array, return False
    if currpos > len(arr):
        return False
    
    # Recursive case: attempt to teleport to the next position based on the current array value
    teleport = dfs(currpos + arr[currpos - 1], arr, target)
    
    # If teleporting leads to the target, return True
    if teleport:
        return True
    
    # If no valid path found, return False
    return False

def main():
    # Read the number of positions (n) and the target position (goal)
    n = int(input())
    goal = int(input())
    
    # Initialize a list to hold the teleportation values
    arr = [0] * (n - 1)
    
    # Populate the list with teleportation values from input
    for i in range(n - 1):
        arr[i] = int(input())
    
    # Call the DFS function starting from position 1 to check if the goal can be reached
    is_found = dfs(1, arr, goal)
    
    # Output the result based on whether the goal was found
    if is_found:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
