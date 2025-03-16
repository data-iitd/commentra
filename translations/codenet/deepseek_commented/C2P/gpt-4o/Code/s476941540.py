import sys

def main():
    alpha = [0] * 26  # Initialize the alpha list to zero for all elements

    # Read characters from standard input until EOF
    for ch in sys.stdin.read():
        # Check if the character is an alphabetic character
        if ch.isalpha():
            # Increment the corresponding element in alpha based on case
            if ch.isupper():
                alpha[ord(ch) - ord('A')] += 1
            else:
                alpha[ord(ch) - ord('a')] += 1

    # Print the counts of each letter from 'a' to 'z'
    for i in range(26):
        print(f"{chr(i + ord('a'))} : {alpha[i]}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
