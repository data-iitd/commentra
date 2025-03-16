# Use the standard library for input/output operations
import sys

# The main function is the entry point of the program
def main():
    # The for loop runs 4 times, each time reading user input and processing it accordingly
    for i in range(4):
        # Read two integers from the user: t and n
        t, n = map(int, sys.stdin.readline().split())

        # Check the value of t and process the input accordingly
        if t == 1:
            print(6000 * n)  # If t is 1, print the result of multiplying n by 6000
        elif t == 2:
            print(4000 * n)  # If t is 2, print the result of multiplying n by 4000
        elif t == 3:
            print(3000 * n)  # If t is 3, print the result of multiplying n by 3000
        elif t == 4:
            print(2000 * n)  # If t is 4, print the result of multiplying n by 2000

# Call the main function to execute the program
if __name__ == "__main__":
    main()
