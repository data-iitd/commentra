# Importing necessary libraries
from typing import List

# Main function starts here
def main():
    N = int(input())  # Number of elements in the vector

    # Declaring two lists X and Y of size N
    X = [0] * N
    Y = [0] * N

    # Filling the lists X and Y with user input
    for i in range(N):
        X[i] = int(input())  # Taking input of X[i] from the user
        Y[i] = X[i]  # Assigning X[i] to Y[i]

    # Sorting the list Y in ascending order
    Y.sort()

    # Finding the middle element of sorted list Y
    y = Y[N // 2]

    # Iterating through the list X and printing the middle element of Y based on the condition
    for i in range(N):
        if X[i] < Y[N // 2]:  # Checking if X[i] is less than the middle element of Y
            print(Y[N // 2])  # If true, print the middle element of Y
        else:  # If X[i] is greater than or equal to the middle element of Y
            print(Y[N // 2 - 1])  # Print the middle element of Y - 1
            break  # Exit the loop as we have found the required element

# End of main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
