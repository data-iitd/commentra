# Import the sys module for input/output operations
import sys

# Begin the main function
def main():
    a = int(input())  # Read an integer value from the user and store it in variable 'a'

    # Calculate the value of the expression (a + (a * a) + (a * a * a)) and print it
    print(a + (a * a) + (a * a * a))

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
