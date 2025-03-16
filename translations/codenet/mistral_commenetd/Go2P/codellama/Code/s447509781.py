
# Package main is the entry point of the program
import sys

# Define the main function
def main():
    # Initialize the input reader
    input = Input(sys.stdin)

    # Read the first integer from the input
    n = input.next_int()

    # Read the second integer array from the input
    s = input.next_int_array()

    # Initialize a boolean slice of size n
    u = [False] * n

    # Initialize two integer variables m and f
    m, f = 0, 0

    # Iterate through all the subarrays of size c+1, where c ranges from 1 to n-2
    for c in range(1, n-1):
        # Initialize a variable f to 0
        f = 0

        # Iterate through all the subarrays of size c+1, where k ranges from 0 to n-1-c*c
        for k in range(0, n-1-c*c):
            # Set the boolean value of the current index to true
            u[k*c] = True

            # Check if the boolean value of the last index of the current subarray is already set to true
            # If it is, break the inner loop as we don't need to check further
            if u[n-1-k*c]: break

            # Calculate the sum of the current and previous subarrays
            f += s[n-1-k*c] + s[k*c]

            # Update the value of m if the current sum is greater than the previous maximum sum
            if m < f: m = f

            # Set all the boolean values of the current subarray to false
        for k in range(0, k*c): u[k*c] = False

    # Print the maximum sum
    print(m)

# Define the Input struct and its methods for reading input
class Input:
    def __init__(self, reader):
        self.reader = reader

    def next_line(self):
        # Read a line from the input and return it as a string

    def next_int(self):
        # Read an integer from the input and return it

    def next_int_array(self):
        # Read an array of integers from the input and return it

# Define the Input struct and its methods for reading input ends here

