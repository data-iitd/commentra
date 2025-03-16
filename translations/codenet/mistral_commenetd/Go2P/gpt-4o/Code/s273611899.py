# Importing the 'sys' module for input/output operations
import sys

# Function main is the entry point of the program
def main():
    # Loop infinitely until user inputs 0 for both 'n' and 'x'
    while True:
        # Read user input for 'n' and 'x'
        n, x = map(int, sys.stdin.readline().split())

        # Check if user has entered 0 for both 'n' and 'x' to break the loop
        if n == 0 and x == 0:
            break

        # Declaring a variable 'c' to store the count of triples
        c = 0

        # Inner loop to find triples that sum up to 'x'
        for i in range(1, n - 1):
            # Inner loop to compare 'j' with all the remaining numbers
            for j in range(i + 1, n):
                # Inner loop to compare 'k' with all the remaining numbers
                for k in range(j + 1, n + 1):
                    # Check if the sum of 'i', 'j', and 'k' equals 'x'
                    if i + j + k == x:
                        # Increment the count 'c' if the condition is true
                        c += 1

        # Print the count of triples that sum up to 'x'
        print(c)

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
