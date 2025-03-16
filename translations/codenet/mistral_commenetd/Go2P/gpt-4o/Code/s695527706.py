# Import the necessary modules
import sys

def main():
    # Read the input from standard input
    input_data = sys.stdin.read().strip().split()
    n = int(input_data[0])  # First input is an integer
    s = input_data[1]        # Second input is a string

    # Count the occurrences of "ABC" in the string s
    count = s.count("ABC")

    # Print the result
    print(count)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
