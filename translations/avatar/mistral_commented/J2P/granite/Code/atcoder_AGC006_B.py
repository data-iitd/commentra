

import sys # Importing sys module for reading input from the console

def print(x, n): # Function to print the answer based on the given input
    max = n * 2 - 1 # Calculating the maximum index for the sequence

    if x == 1 or x == max: # Checking if x is the first or last index in the sequence
        print("No") # If true, print "No" and return
        return

    print("Yes") # If false, print "Yes"
    ans = "\n".join(str((i + x + n - 1) % max + 1) for i in range(n)) # Generating a sequence of integers from x+n-1 to x+n+max-1
    print(ans) # Printing the final answer

if __name__ == "__main__": # Main block to start the execution of the program
    x, n = map(int, sys.stdin.readline().split()) # Reading the input from the console and converting them to integers
    print(x, n) # Calling the print function with x and n as arguments

