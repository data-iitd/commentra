# Import the sys module for reading input
import sys

def main():
    n = int(sys.stdin.readline().strip())  # Read an integer `n` from the standard input
    c = [''] * n  # Create a new list `c` of size `n`
    p = ord('a')  # Get the ASCII value of the character 'a'

    for i in range(4):  # Use a for loop to iterate through the first four elements of the list
        for j in range(i, n, 4):  # Use a nested for loop to populate every fourth element of the list
            c[j] = chr(p)  # Set the current element of the list to the current character
            p += 1  # Increment the character to be added to the next element

    for i in range(n):  # Use a for loop to print each character in the list
        print(c[i], end='')  # Print each character without a newline

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
