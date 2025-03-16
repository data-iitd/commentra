
# Include the standard input/output library
import sys

# Start of the main function
def main():
    r = float(input()) # Read a value of type double from the standard input and store it in variable 'r'

    s = r*r*3.141592653589 # Calculate the area of a circle with radius 'r' and store it in variable's'
    l = 2*3.141592653589*r # Calculate the circumference of a circle with radius 'r' and store it in variable 'l'

    print(s,l) # Print the values of's' and 'l' to the standard output

# End of the main function and return 0 to indicate successful execution
if __name__ == "__main__":
    main()

