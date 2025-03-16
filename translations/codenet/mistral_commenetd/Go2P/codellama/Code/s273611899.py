
# Importing the 'sys' package for input/output operations
import sys

# Function main is the entry point of the program
def main():
    # Declaring two integer variables 'n' and 'x'
    n, x = map(int, input().split())

    # Loop infinitely until user inputs 0 for both 'n' and 'x'
    while n != 0 and x != 0:
        # Declaring an integer variable 'c' to store the count of triples
        c = 0

        # Inner loop to find triples that sum up to 'x'
        for i in range(1, n-2+1):
            # Inner loop to compare 'j' with all the remaining numbers
            for j in range(i+1, n-1+1):
                # Inner loop to compare 'k' with all the remaining numbers
                for k in range(j+1, n+1):
                    # Check if the sum of 'i', 'j', and 'k' equals 'x'
                    if i+j+k == x:
                        # Increment the count 'c' if the condition is true
                        c += 1

        # Print the count of triples that sum up to 'x'
        print(c)

        # Read user input for 'n' and 'x'
        n, x = map(int, input().split())

# Call the main function
main()

