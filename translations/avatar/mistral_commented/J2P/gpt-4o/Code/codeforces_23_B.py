# Import the necessary module for reading input
import sys

# Function to calculate the maximum sum of elements to the left of a given index
def max_left(n):
    # Return the maximum left sum, which is the sum of elements from index 0 to the given index - 2
    return n - 2 if n > 2 else 0

# Main function to execute the program
def main():
    # Read the number of test cases from the input
    t = int(sys.stdin.readline().strip())

    # Iterate through each test case
    for _ in range(t):
        n = int(sys.stdin.readline().strip())  # Read the number of elements in the array

        # Print the maximum left sum
        print(max_left(n))

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
