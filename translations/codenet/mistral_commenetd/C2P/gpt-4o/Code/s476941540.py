# Import the necessary module
import sys

# The main function is the starting point of the program
def main():
    alpha = [0] * 26  # Declare a list 'alpha' of size 26 initialized to zero

    # Start an infinite loop
    while True:
        ch = sys.stdin.read(1)  # Read a character from the standard input

        # If the character read is End-Of-File (EOF), break the loop
        if ch == '':
            break

        # If the character is an alphabetic character
        if ch.isalpha():
            # If the character is an uppercase letter, increment the corresponding element in the list 'alpha'
            if ch.isupper():
                alpha[ord(ch) - 65] += 1
            # If the character is a lowercase letter, increment the corresponding element in the list 'alpha'
            else:
                alpha[ord(ch) - 97] += 1

    # Initialize the character 'ch' with the ASCII value of 'a'
    ch = 'a'

    # Print the count of each alphabetic character and its corresponding ASCII value
    for i in range(26):
        print(f"{ch} : {alpha[i]}")
        ch = chr(ord(ch) + 1)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
