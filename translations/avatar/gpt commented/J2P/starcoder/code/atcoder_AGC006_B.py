import sys; # Importing sys module for reading input from the user

def print(x, n):
    # Calculating the maximum value based on n
    max = n * 2 - 1;
    
    # Checking if x is equal to 1 or max, if so, print "No" and exit the method
    if x == 1 or x == max:
        print("No")
        return # Exit the method early
    
    # If x is valid, print "Yes"
    print("Yes")
    
    # Prepare the line separator for formatting output
    sep = "\n"
    
    # Generate a sequence of numbers based on the input x and n
    ans = sep.join(str((e % max + 1)) for e in range(x + n - 1, x + n + max - 1))
    
    # Print the generated sequence
    print(ans)

if __name__ == "__main__":
    # Reading two integers from user input: n and x
    n = int(sys.stdin.readline())
    x = int(sys.stdin.readline())
    
    # Calling the print method with the inputs x and n
    print(x, n)

