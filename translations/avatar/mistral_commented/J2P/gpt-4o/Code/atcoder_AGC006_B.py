# Importing the sys module for reading input from the console
import sys

def main():
    # Reading the first integer input from the user
    n = int(sys.stdin.readline().strip())
    # Reading the second integer input from the user
    x = int(sys.stdin.readline().strip())
    # Calling the print function with x and n as arguments
    print_result(x, n)

def print_result(x, n):
    # Calculating the maximum index for the sequence
    max_index = n * 2 - 1

    # Checking if x is the first or last index in the sequence
    if x == 1 or x == max_index:
        print("No")  # If true, print "No" and return
        return

    print("Yes")  # If false, print "Yes"
    # Generating a sequence of integers from x+n-1 to x+n+max-1
    result = []
    for e in range(x + n - 1, x + n + max_index - 1):
        # Appending the next integer to the result list
        result.append(str((e % max_index) + 1))

    # Printing the final answer, joining the list with new lines
    print("\n".join(result))

if __name__ == "__main__":
    main()  # Starting the execution of the program

# <END-OF-CODE>
