# Importing necessary libraries
import sys

# Defining a constant INF for a very large number
INF = int(1e9) + 5

def main():
    # Reading the integer value of n
    n = int(input())

    # Initializing two lists to store the elements
    a = []
    b = []

    # Initializing variables to track the minimum and maximum values
    left = INF
    right = 0

    # Looping through n elements to read and update the lists and variables
    for i in range(n):
        a_i, b_i = map(int, input().split())  # Reading elements into lists a and b
        a.append(a_i)
        b.append(b_i)
        left = min(left, a[i])  # Updating left with the minimum value
        right = max(right, b[i])  # Updating right with the maximum value

    # Looping through the lists to find the target element
    for i in range(n):
        if left == a[i] and right == b[i]:
            print(i + 1)  # Printing the 1-based index of the target element
            return  # Returning from the method after finding the target

    # If no such element is found, print -1
    print(-1)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
