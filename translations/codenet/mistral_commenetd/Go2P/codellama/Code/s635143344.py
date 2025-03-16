
# Import the required modules
import sys

# Function main is the entry point of the program
def main():
    # Initialize an integer list named in with a length of 3
    in = [0, 0, 0]

    # Use input function to read three integers from the standard input and store them in the list in
    in[0] = int(input())
    in[1] = int(input())
    in[2] = int(input())

    # Sort the integers in ascending order using sorted function
    in.sort()

    # Multiply the last integer by 10 and add the second last and the last integer
    # Then print the result using print function
    print(in[2] * 10 + in[1] + in[0])

# Call the main function
main()

