# Import the necessary module
import sys

def main():
    # Read a line of input from the user
    s = input()
    length = len(s)  # Calculate the length of the string s
    ch = ''  # Initialize a character variable ch

    # Iterate through the string s in reverse order
    for i in range(length - 1, -1, -1):
        if s[i] != ' ' and s[i] != '?':  # Check if the current character is not a space or a question mark
            ch = s[i]  # Assign the current character to the variable ch
            break  # Exit the loop

    ch = ch.lower()  # Convert the character ch to lowercase

    # Check if ch is one of the vowels (a, e, i, o, u, y)
    if ch in 'aeiouy':
        print("YES")  # Print "YES" if ch is a vowel
    else:
        print("NO")  # Print "NO" if ch is not a vowel

if __name__ == "__main__":
    main()

# <END-OF-CODE>
