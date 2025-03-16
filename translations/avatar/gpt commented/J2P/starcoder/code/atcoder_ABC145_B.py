# Importing the utility package for Scanner
import java.util.*;

# Importing the math package (not used in this code)
import java.math.*;

# Method to print a string to the console
def cout(str):
    print(str)

# Main method where the program execution begins
def main():
    # Creating a Scanner object to read input from the console
    cin = Scanner(System.in)

    # Initializing variables to hold parts of the input string
    a = ""
    b = ""
    str = ""

    # Reading an integer input which represents the length of the string
    n = cin.nextInt()
    cin.nextLine() # Consuming the newline character after the integer input

    # Reading the actual string input
    str = cin.nextLine()

    # Loop to construct the first half of the string
    for i in range(0, n / 2):
        a = a + str[i] # Appending characters from the first half of the string to 'a'

    # Checking if the string is made up of two identical halves
    if (str.equals(a + a)):
        cout("Yes") # If true, print "Yes"
    else:
        cout("No") # If false, print "No"

# Calling the main method
if __name__ == "__main__":
    main()

