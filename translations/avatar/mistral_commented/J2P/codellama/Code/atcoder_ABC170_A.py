# Importing necessary Python modules for reading input from the console and writing output to the console
import sys

# Main method is the entry point of the Python application
def main():

    # Reading input array from the console
    input_array = sys.stdin.readline().split()

    # Initializing result variable to 0
    result = 0

    # Iterating through each string in the input array
    for str in input_array:

        # Incrementing result variable for each non-zero string encountered
        result += 1

        # Breaking the loop if a zero string is encountered
        if str == "0":
            break

    # Writing the result to the console
    print(result)

# Calling the main method
main()

# End of code
