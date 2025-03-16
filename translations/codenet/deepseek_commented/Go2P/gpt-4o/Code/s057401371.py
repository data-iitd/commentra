def main():
    s = input()

    # Define the difference between lowercase and uppercase ASCII values
    d = ord('a') - ord('A')

    # Iterate over each character in the input string
    for r in s:
        rr = r
        # Check if the character is an uppercase letter
        if 'A' <= r <= 'Z':
            # Convert uppercase to lowercase
            rr = chr(ord(r) + d)
        elif 'a' <= r <= 'z':
            # Convert lowercase to uppercase
            rr = chr(ord(r) - d)
        # Print the converted character
        print(rr, end='')

    print()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
