# Importing the necessary modules
import sys  # Importing sys for standard input/output

def main():
    # Reading the first number from the user input
    n = int(input("Enter a number: "))  # Converting input to an integer

    print(n)  # Printing the first number to the standard output

    m = n  # Initializing a variable 'm' with the value of 'n'

    # Finding the factors of the number 'n' using a for loop
    for i in range(n - 1, 0, -1):  # Looping from n-1 down to 1
        if m % i == 0:  # Checking if 'i' is a factor of 'm'
            print(i)  # Printing the factor to the standard output
            m = i  # Updating the value of 'm' with the current factor

if __name__ == "__main__":
    main()  # Calling the main function to execute the code

# <END-OF-CODE>
