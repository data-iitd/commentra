import sys; # Importing the sys module for input operations

def print(x, n): # Function to print based on the value of x and n
    max = n * 2 - 1; # Calculate the maximum value based on n
    if x == 1 or x == max: # Check if x is at the edges
        print("No"); # Print "No" if x is 1 or max
        return; # Exit the method
    print("Yes"); # Print "Yes" if x is within the valid range
    sep = sys.stdin.readline(); # Get the system's line separator
    ans = "".join(str((e % max + 1) + sep) for e in range(x + n - 1, x + n + max - 1)); # Generate a string of numbers
    print(ans); # Print the constructed string

if __name__ == "__main__": # Check if the code is being run directly
    x = int(input()); # Read the first integer input
    n = int(input()); # Read the second integer input
    print(x, n); # Call the print method with x and n as arguments

