import sys

def main():
    # Read the input string
    s = input().strip()

    # Start checking for the first missing lowercase letter from 'a'
    c = 'a'

    # Loop through all lowercase letters from 'a' to 'z'
    for j in range(26):
        found = False  # Flag to check if the current letter is found in the input string
        # Check if the current letter exists in the input string
        for i in range(len(s)):
            if s[i] == c:
                found = True  # Set the flag to true if the letter is found
                break
        # If the letter was not found, print it and exit
        if not found:
            print(c)
            return
        c = chr(ord(c) + 1)  # Move to the next letter

    # If all letters from 'a' to 'z' are found, print "None"
    print("None")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
