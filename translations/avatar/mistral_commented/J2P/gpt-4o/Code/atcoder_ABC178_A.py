# Importing necessary libraries for this program
import sys

def main():
    # Reading an integer value from the user input
    x = int(input().strip())

    # Determining a boolean value based on the condition x equals to 1
    bool_value = (x == 1)

    # Calculating the result based on the boolean value
    result = 0 if bool_value else 1

    # Writing the result to the standard output
    print(result)

# Entry point of the Python application
if __name__ == "__main__":
    main()

# <END-OF-CODE>
