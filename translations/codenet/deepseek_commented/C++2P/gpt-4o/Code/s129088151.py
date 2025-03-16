# Import the necessary libraries
import sys

def main():
    n = int(input())  # Read the number of operations from the user
    T = {}  # Declare a dictionary to store the presence of strings

    for _ in range(n):  # Loop through each operation
        com, str_value = input().split()  # Read the command and the string
        if com[0] == 'i':  # If the command is 'i', insert the string into the dictionary
            T[str_value] = True
        else:  # If the command is not 'i'
            if str_value in T:  # Check if the string is present in the dictionary
                print("yes")  # Print 'yes' if present
            else:
                print("no")  # Print 'no' if not present

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
