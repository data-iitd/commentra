# Import the necessary libraries
import sys

def main():
    n = int(input())  # Read the value of n from the standard input
    a = int(input())  # Read the value of a from the standard input
    sum = 0  # Initialize a variable to store the sum of the last 'a' elements
    s = []  # Declare a list to store the elements

    for _ in range(n):  # Loop to read 'n' elements into the list 's'
        s.append(int(input()))  # Read the elements from the standard input

    s.sort()  # Sort the list 's' in ascending order
    for i in range(n - 1, n - a - 1, -1):  # Loop to calculate the sum of the last 'a' elements
        sum += s[i]  # Add the value of the current element to the sum

    print(sum)  # Print the calculated sum to the standard output

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
