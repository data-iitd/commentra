# Import the sys module to read from standard input
import sys

def main():
    # Initialize a list to count occurrences of each letter
    alpha = [0] * 26

    # Read characters from standard input until EOF
    for ch in sys.stdin.read():
        # Check if the character is an alphabet letter
        if ch.isalpha():
            # If the character is uppercase, increment the corresponding index in the alpha list
            if ch.isupper():
                alpha[ord(ch) - ord('A')] += 1  # 'A' is at index 0, 'B' at index 1, ..., 'Z' at index 25
            else:
                # If the character is lowercase, increment the corresponding index in the alpha list
                alpha[ord(ch) - ord('a')] += 1  # 'a' is at index 0, 'b' at index 1, ..., 'z' at index 25

    # Print the count of each letter from 'a' to 'z'
    for i in range(26):
        print(f"{chr(i + ord('a'))} : {alpha[i]}")  # Output the letter and its count

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
