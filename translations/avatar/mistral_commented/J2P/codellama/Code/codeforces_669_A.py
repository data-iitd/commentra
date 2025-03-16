
import sys

def solve(n):
    # Calculate the result and print it to the console
    print((n // 3) * 2 + (n % 3 == 0) * 1)

# Main method is the entry point of the Python application
if __name__ == "__main__":
    # Read the input number from the console and store it in the 'n' variable
    n = int(sys.stdin.readline().strip())

    # Call the 'solve' method to calculate and print the result
    solve(n)

# END-OF-CODE
