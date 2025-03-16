# Import the necessary libraries
import sys  # Import sys for standard input/output

def main():  # Define the main function
    x = int(sys.stdin.readline().strip())  # Read an integer value from standard input

    if x == 1:  # Check if the value of x is equal to 1
        print("0")  # If x is 1, print 0 to the standard output
    else:  # If x is not equal to 1
        print("1")  # Otherwise, print 1 to the standard output

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
