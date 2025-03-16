# Import the necessary module
import sys

def main():
    s = input()  # Read a string input from the standard input

    a, z = -1, -1  # Initialize variables a and z to -1

    for i in range(len(s)):  # Iterate through each character in the string s
        if s[i] == 'A':  # Check if the current character is 'A'
            a = i  # Assign the index of 'A' to a
            break  # Exit the loop once 'A' is found

    for i in range(len(s) - 1, -1, -1):  # Iterate through the string in reverse order
        if s[i] == 'Z':  # Check if the current character is 'Z'
            z = i  # Assign the index of 'Z' to z
            break  # Exit the loop once 'Z' is found

    print(z - a + 1)  # Output the difference between the indices of 'Z' and 'A' plus one

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
