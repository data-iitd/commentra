
import sys # Importing sys for exit function

# Defining a constant INF for a very large number
INF = 1000000005

def main():
    # Creating a Scanner object to read input
    n = int(input()) # Reading the integer value of n

    # Initializing two lists to store the elements
    a = []
    b = []

    # Initializing variables to track the minimum and maximum values
    left = INF
    right = 0

    # Looping through n elements to read and update the lists and variables
    for i in range(n):
        a.append(int(input())) # Reading element into list a
        b.append(int(input())) # Reading element into list b
        left = min(left, a[i]) # Updating left with the minimum value
        right = max(right, b[i]) # Updating right with the maximum value

    # Looping through the lists to find the target element
    for i in range(n):
        if left == a[i] and right == b[i]:
            print(i + 1) # Printing the 1-based index of the target element
            sys.exit() # Exiting the program after finding the target

    # If no such element is found, print -1
    print(-1)

if __name__ == "__main__":
    main()

