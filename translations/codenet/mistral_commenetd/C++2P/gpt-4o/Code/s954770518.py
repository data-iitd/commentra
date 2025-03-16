# Import the necessary libraries
import sys

def main():
    s = []  # Initialize an empty list to store the integers

    # Read 10 integers from the user and store them in the list 's'
    for _ in range(10):
        s.append(int(sys.stdin.readline().strip()))  # Read an integer from standard input and append it to the list

    # Sort the list 's' in ascending order
    s.sort()

    # Print the 4th, 5th, and 6th smallest elements from the sorted list 's'
    for i in range(9, 6, -1):  # Loop from index 9 to 7 (exclusive)
        print(s[i])  # Print the current element of the list 's'

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
