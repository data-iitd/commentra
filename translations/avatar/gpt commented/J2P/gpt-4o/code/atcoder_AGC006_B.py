# Importing the necessary module for user input
import sys

def main():
    # Reading two integers from user input: n and x
    n = int(input())
    x = int(input())
    
    # Calling the print method with the inputs x and n
    print_result(x, n)

def print_result(x, n):
    # Calculating the maximum value based on n
    max_value = n * 2 - 1
    
    # Checking if x is equal to 1 or max_value, if so, print "No" and exit the method
    if x == 1 or x == max_value:
        print("No")
        return  # Exit the method early
    
    # If x is valid, print "Yes"
    print("Yes")
    
    # Prepare the line separator for formatting output
    sep = "\n"
    
    # Generate a sequence of numbers based on the input x and n
    ans = ''.join(str((e % max_value) + 1) + sep for e in range(x + n - 1, x + n + max_value - 1))
    
    # Print the generated sequence
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
