
# Importing the necessary package for input and other utilities
import sys

# Main class definition
class Main:
    def dfs(self, currpos, arr, target):
        # Depth-first search method to find if the target position can be reached
        if currpos == target: return True # If current position is the target, return true
        if currpos == len(arr) + 1: return False # If current position exceeds array length, return false

        teleport = self.dfs(currpos + arr[currpos - 1], arr, target) # Recursive call with teleported position
        if teleport: return True # If teleportation leads to the target, return true
        return False # Otherwise, return false

    def main(self):
        # Main method where the program execution begins
        n = int(sys.stdin.readline()) # Reading the number of elements in the array
        goal = int(sys.stdin.readline()) # Reading the target position
        arr = [int(sys.stdin.readline()) for i in range(n - 1)] # Initializing the array with n-1 elements

        isFound = self.dfs(1, arr, goal) # Calling the dfs method with initial position 1
        if isFound: print("YES") # If the target position is found, print "YES"
        else print("NO") # Otherwise, print "NO"

# End of code

