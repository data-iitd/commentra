# Import necessary libraries
import sys

# The main function from where the execution begins
def main():
    # Declare variables
    n = int(input())  # Read the number of elements from the standard input
    a = [0] * 100     # Declare and initialize an array of size 100 with zeros
    avg = 0           # Average of the elements in the array
    s = 0             # Difference between the first element and the average
    ans = 0           # Index of the element with the maximum difference from the average

    # Calculate the average of the elements in the array
    for i in range(n):
        a[i] = int(input())  # Read an element from the standard input and store it in the array
        avg += a[i]          # Add the current element to the sum of all elements

    # Calculate the average and divide it by the number of elements
    avg /= n

    # Initialize the difference between the first element and the average
    s = abs(a[0] - avg)

    # Initialize the index of the element with the maximum difference from the average
    ans = 0

    # Find the index of the element with the maximum difference from the average
    for i in range(1, n):
        if s > abs(a[i] - avg):  # If the current difference is greater than the previous difference
            s = abs(a[i] - avg)  # Update the difference
            ans = i               # Update the index

    # Print the index of the element with the maximum difference from the average
    print(ans)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
