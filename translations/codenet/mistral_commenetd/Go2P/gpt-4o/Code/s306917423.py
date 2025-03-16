# Importing the 'sys' module for input/output operations
import sys

def main():
    # Reading the string input from standard input
    s = sys.stdin.read().strip()

    # Initializing the answer to zero
    ans = 0

    # Looping through each character 'c' in the string 's'
    for c in s:
        # Checking if the current character 'c' is equal to '1'
        if c == '1':
            # Incrementing the answer if the character is '1'
            ans += 1

    # Printing the answer
    print(ans)

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
