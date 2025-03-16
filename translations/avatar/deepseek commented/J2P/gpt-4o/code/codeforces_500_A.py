def dfs(currpos, arr, target):
    # Depth-first search method to find if the target position can be reached
    if currpos == target:
        return True  # If current position is the target, return true
    if currpos > len(arr):  # Adjusted to check if currpos exceeds array length
        return False  # If current position exceeds array length, return false

    teleport = dfs(currpos + arr[currpos - 1], arr, target)  # Recursive call with teleported position
    if teleport:
        return True  # If teleportation leads to the target, return true
    return False  # Otherwise, return false

def main():
    # Main function where the program execution begins
    n = int(input())  # Reading the number of elements in the array
    goal = int(input())  # Reading the target position
    arr = [0] * (n - 1)  # Initializing the array with n-1 elements

    for i in range(n - 1):
        arr[i] = int(input())  # Reading the array elements

    is_found = dfs(1, arr, goal)  # Calling the dfs method with initial position 1
    if is_found:
        print("YES")  # If the target position is found, print "YES"
    else:
        print("NO")  # Otherwise, print "NO"

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
