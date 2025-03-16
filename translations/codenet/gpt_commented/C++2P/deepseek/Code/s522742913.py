import sys
import math

def main():
    # Read input from the user
    source = input()

    # Check if the input length is valid (between 1 and 10 characters)
    if len(source) > 10 or len(source) < 1:
        # Return -1 if the input length is invalid
        return -1

    # Calculate the maximum number of combinations of '+' placements
    max_i = int(math.pow(2, len(source) - 1))

    # Initialize a variable to hold the cumulative sum of the evaluated expressions
    sum_ = 0

    # Iterate through all possible combinations of '+' placements
    for i in range(max_i):
        # Create a bitset to represent the current combination of '+' placements
        plus = bin(i)[2:].zfill(len(source) - 1)

        # Initialize a variable to hold the current number being evaluated
        number = 0

        # Create a working copy of the source string to manipulate
        working = source
        # While there are still '+' placements to evaluate
        for bit in plus:
            if bit == '1':
                # Convert the substring up to the current position to a float and add to sum
                sum_ += float(working)
                # Update the working string to remove the processed segment
                working = working[working.find('+'):]

        # Add the remaining part of the working string to the sum
        sum_ += float(working)

    # Print the final sum
    print("{:.0f}".format(sum_))

if __name__ == "__main__":
    if main() == -1:
        sys.exit(-1)
