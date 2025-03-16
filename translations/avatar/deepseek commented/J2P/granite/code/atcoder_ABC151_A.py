

import sys

def main():
    # Read a single line of input from the user
    s = input()

    # Increment the first character of the input by 1 and print it
    print(chr(ord(s[0]) + 1), end='')

if __name__ == "__main__":
    main()

