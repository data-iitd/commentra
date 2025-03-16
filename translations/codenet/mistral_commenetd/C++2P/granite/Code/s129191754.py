

import sys

def main():
    # Read the number of elements in the vector
    n = int(input())

    # Initialize a list of size n with default-constructed elements
    a = [0] * n

    # Read the elements of the vector
    for i in range(n):
        a[i] = int(input())

    # Sort the list in ascending order
    a.sort()

    # Check if there are any consecutive elements in the sorted list
    for i in range(n-1):
        # If there are consecutive elements, print "NO" and exit the program
        if a[i] == a[i+1]:
            print("NO")
            sys.exit(0)

    # If no consecutive elements were found, print "YES"
    print("YES")

if __name__ == "__main__":
    main()

