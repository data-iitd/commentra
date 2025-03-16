
import sys # Importing the necessary package for input and other utilities

def dfs(currpos, arr, target):
    # Depth-first search method to find if the target position can be reached
    if currpos == target: return True # If current position is the target, return True
    if currpos == len(arr) + 1: return False # If current position exceeds array length, return False

    teleport = dfs(currpos + arr[currpos - 1], arr, target) # Recursive call with teleported position
    if teleport: return True # If teleportation leads to the target, return True
    return False # Otherwise, return false

def main():
    # Main method where the program execution begins
    n, goal = map(int, sys.stdin.readline().split()) # Reading the number of elements in the array and the target position
    arr = list(map(int, sys.stdin.readline().split())) # Reading the array elements

    isFound = dfs(1, arr, goal) # Calling the dfs method with initial position 1
    if isFound: print("YES") # If the target position is found, print "YES"
    else: print("NO") # Otherwise, print "NO"

if __name__ == "__main__":
    main() # Calling the main method

