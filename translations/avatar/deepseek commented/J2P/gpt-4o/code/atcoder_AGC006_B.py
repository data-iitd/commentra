# Importing the necessary module for input operations
import sys

def main():
    n = int(input())  # Read the first integer input
    x = int(input())  # Read the second integer input
    print_result(x, n)  # Call the print_result function with x and n as arguments

def print_result(x, n):
    max_value = n * 2 - 1  # Calculate the maximum value based on n
    if x == 1 or x == max_value:  # Check if x is at the edges
        print("No")  # Print "No" if x is 1 or max
        return  # Exit the function
    print("Yes")  # Print "Yes" if x is within the valid range
    sep = "\n"  # Define the line separator
    ans = ''.join(str((e % max_value) + 1) + sep for e in range(x + n - 1, x + n + max_value - 1))  # Generate the required output
    print(ans)  # Print the constructed string

if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
