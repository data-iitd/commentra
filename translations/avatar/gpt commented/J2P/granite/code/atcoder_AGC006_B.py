
import sys # Importing sys module for reading input from the user

def print(x, n):
    max = n * 2 - 1 # Calculating the maximum value based on n
    
    if x == 1 or x == max: # Checking if x is equal to 1 or max, if so, print "No" and exit the method
        print("No")
        sys.exit() # Exit the method early
    
    print("Yes") # If x is valid, print "Yes"
    
    ans = "\n".join(str((i + x + n - 1) % max + 1) for i in range(n)) # Generate a sequence of numbers based on the input x and n
    
    print(ans) # Print the generated sequence

if __name__ == "__main__":
    n, x = map(int, input().split()) # Reading two integers from user input: n and x
    print(x, n) # Calling the print method with the inputs x and n

