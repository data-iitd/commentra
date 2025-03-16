# Importing the necessary module for input
import sys

# Function to print a string to the console
def cout(str):
    print(str)

# Main function where the program execution begins
def main():
    # Reading an integer input which represents the length of the string
    n = int(input().strip())
    
    # Reading the actual string input
    str_input = input().strip()

    # Initializing a variable to hold the first half of the string
    a = ""

    # Loop to construct the first half of the string
    for i in range(n // 2):
        a += str_input[i]  # Appending characters from the first half of the string to 'a'

    # Checking if the string is made up of two identical halves
    if str_input == a + a:
        cout("Yes")  # If true, print "Yes"
    else:
        cout("No")   # If false, print "No"

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
