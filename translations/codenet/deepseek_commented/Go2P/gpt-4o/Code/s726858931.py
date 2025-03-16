def main():
    # Read the input string.
    s = input().strip()

    # Initialize the character to check against the string.
    c = 'a'

    # Iterate through the alphabet to find the first missing character.
    for j in range(26):
        if c not in s:
            print(c)
            return
        c = chr(ord(c) + 1)

    # If no missing character is found, print "None".
    print("None")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
