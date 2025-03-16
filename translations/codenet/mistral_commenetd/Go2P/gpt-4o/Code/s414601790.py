# Importing the necessary module for input/output operations
import sys

def main():
    # Reading input from the user
    n, s = input().split()
    n = int(n)  # Converting the first input to an integer

    # Variable declaration and initialization for maximum count and current count
    max_count = 0
    current_count = 0

    # Iterating through each character in the string 's'
    for r in s:
        # Checking if the character is 'I'
        if r == 'I':
            # Incrementing the current count
            current_count += 1
        else:
            # Decrementing the current count
            current_count -= 1

        # Updating the maximum count if the current count is greater
        if current_count > max_count:
            max_count = current_count

    # Printing the maximum count
    print(max_count)

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
