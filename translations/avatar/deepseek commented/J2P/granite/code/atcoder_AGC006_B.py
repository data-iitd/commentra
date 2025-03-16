
import sys # Importing the sys module for input operations

def print(x, n):
    max = n * 2 - 1 # Calculate the maximum value based on n
    if x == 1 or x == max: # Check if x is at the edges
        print("No") # Print "No" if x is 1 or max
        return # Exit the function
    print("Yes") # Print "Yes" if x is within the valid range
    ans = "\n".join(str((i % max + 1)) for i in range(x + n - 1, x + n + max - 1)) # Generate a string of numbers
    print(ans) # Print the constructed string

def main():
    n, x = map(int, sys.stdin.readline().split()) # Read the input as a list of integers
    print(x, n) # Call the print function with x and n as arguments

if __name__ == "__main__":
    main() # Call the main function

