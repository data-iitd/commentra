# Importing the sys module for input operations
import sys

def main():  # The main function, the entry point of the program
    t = int(sys.stdin.readline().strip())  # Reading the number of test cases
    for _ in range(t):  # Looping through each test case
        n = int(sys.stdin.readline().strip())  # Reading the value of n for each test case
        print(max_left(n))  # Calling the max_left function and printing the result

def max_left(n):  # Defining the max_left function
    return n - 2 if n > 2 else 0  # Returning n - 2 if n is greater than 2, otherwise returning 0

if __name__ == "__main__":  # Ensuring the main function runs only when the script is executed directly
    main()

# <END-OF-CODE>
