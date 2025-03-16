# Importing the sys module for standard input/output
import sys

def main():  # Declaring the main function
    a, b = map(int, sys.stdin.readline().split())  # Reading two integers from the user and storing them in variables a and b

    s = (a * b) - (a + b) + 1  # Calculating the value of s by multiplying a and b, subtracting the sum of a and b, and adding 1

    # The following line prints the value of s to the console
    print(s)

if __name__ == "__main__":  # Ensuring the main function runs when the script is executed
    main()

# <END-OF-CODE>
