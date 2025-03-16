
import sys; # Importing sys module for reading input from the console

def print(x, n): # Function to print the answer based on the given input
    max = n * 2 - 1; # Calculating the maximum index for the sequence

    if x == 1 or x == max: # Checking if x is the first or last index in the sequence
        print("No"); # If true, print "No" and return
        return;

    print("Yes"); # If false, print "Yes"
    sep = "\n"; # Creating a separator string for new lines
    ans = "".join(str(e % max + 1) + sep for e in range(x + n - 1, x + n + max - 1)); # Generating a sequence of integers from x+n-1 to x+n+max-1
    print(ans); # Printing the final answer

if __name__ == "__main__": # Main method to start the execution of the program
    x = int(sys.stdin.readline()); # Reading the first integer input from the user
    n = int(sys.stdin.readline()); # Reading the second integer input from the user
    print(x, n); # Calling the print method with x and n as arguments

