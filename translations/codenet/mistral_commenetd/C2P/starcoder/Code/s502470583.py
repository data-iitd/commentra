
# Include the standard input/output library
import sys

# Start of the main function
def main():
    # Declare four integer variables a, b, c, and d
    a = 0
    b = 0
    c = 0
    d = 0

    # Read two integers from the user and store them in variables a and b
    a, b = map(int, input().split())

    # Multiply the two integers and store the result in variable c
    c = a * b

    # Multiply each integer with 2 and add them to get the value of d
    d = 2 * a + 2 * b

    # Print the values of c and d on the console
    print(c, d)

# End of the main function and return 0 to indicate successful execution
if __name__ == "__main__":
    main()

