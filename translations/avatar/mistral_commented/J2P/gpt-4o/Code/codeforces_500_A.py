# Importing the necessary module for input and output operations
import sys

def dfs(currpos, arr, target):  # Defining the recursive depth-first search function
    if currpos == target:  # Base case: if the current position is the target position, return True
        return True
    if currpos >= len(arr) + 1:  # Base case: if the current position is out of the array bounds, return False
        return False
    teleport = dfs(currpos + arr[currpos - 1], arr, target)  # Recursive call: try to teleport to the next position
    if teleport:  # If teleportation was successful, return True
        return True
    return False  # If teleportation was not successful, return False

def main():  # Defining the main function
    n = int(input())  # Reading the number of positions in the array from the standard input
    goal = int(input())  # Reading the target position from the standard input
    arr = [0] * (n - 1)  # Creating an array of size n-1 to store the positions of the teleportals
    for i in range(n - 1):  # Reading the positions of the teleportals from the standard input and storing them in the array
        arr[i] = int(input())
    is_found = dfs(1, arr, goal)  # Calling the depth-first search function with the initial position and the target position
    if is_found:  # If the target position was found, print "YES" to the standard output
        print("YES")
    else:  # If the target position was not found, print "NO" to the standard output
        print("NO")

if __name__ == "__main__":  # Ensuring the main function runs only when the script is executed directly
    main()  # Calling the main function

# <END-OF-CODE>
