import sys  # Import sys module for reading input from console

def main():
    # Read the input string from the console
    a = sys.stdin.read().strip()

    # Replace all occurrences of ',' in the 'a' string with a single space
    modified_string = a.replace(',', ' ')

    # Print the modified string to the console
    print(modified_string)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
