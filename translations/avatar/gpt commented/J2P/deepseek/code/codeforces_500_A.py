def dfs(currpos, arr, target):
    # Base case: if the current position equals the target, return True
    if currpos == target:
        return True
    
    # Base case: if the current position exceeds the bounds of the array, return False
    if currpos > len(arr):
        return False
    
    # Recursive case: attempt to teleport to the next position based on the current array value
    teleport = dfs(currpos + arr[currpos - 1] - 1, arr, target)
    
    # If teleporting leads to the target, return True
    if teleport:
        return True
    
    # If no valid path found, return False
    return False

# Main function to read input and execute the DFS
def main():
    # Read the number of positions (n) and the target position (goal)
    n, goal = map(int, input().split())
    
    # Initialize an array to hold the teleportation values
    arr = list(map(int, input().split()))
    
    # Call the DFS function starting from position 1 to check if the goal can be reached
    is_found = dfs(1, arr, goal)
    
    # Output the result based on whether the goal was found
    print("YES" if is_found else "NO")

# Execute the main function
if __name__ == "__main__":
    main()
