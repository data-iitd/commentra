
#include<stdio.h>

# Variables declaration
n = 0
r = 0
i = 0
j = 0
p = 0
c = 0
a = [0] * 100
b = [0] * 100

def main():
    # Infinite loop until user inputs 0 for both n and r
    while True:
        print("Enter the number of elements in array a: ")
        n = int(input())
        print("Enter the number of rotations: ")
        r = int(input())

        if n == 0 and r == 0: # Exit the loop if n and r are both 0
            break

        # Initialize array a with the given size
        for i in range(n):
            a[i] = n - i # Set the initial values of array a

        # Rotate the array r times
        for i in range(r):
            print("\nBefore rotation %d:\n" % (i + 1))
            # Print the current state of array a before rotation
            for j in range(n):
                print("%d " % a[j], end="")
            print("\n")

            # Create a copy of array a and store it in array b
            for j in range(n):
                b[j] = a[j] # Copy each element of array a to array b

            # Read the number of elements to be rotated and the position from user
            print("Enter the number of elements to be rotated: ")
            c = int(input())
            print("Enter the position: ")
            p = int(input())

            # Rotate the array b by c positions to the left
            for j in range(c):
                b[j] = b[j + 1] # Shift each element of array b one position to the left

            # Rotate the first part of array a by c positions to the left
            for j in range(c):
                a[j] = b[p - 1 + j] # Shift each element of the first part of array a by c positions to the left

            # Rotate the second part of array a by (p-c) positions to the right
            for j in range(c, n):
                a[j] = b[j - c] # Shift each element of the second part of array a by (p-c) positions to the right

            # Print the current state of array a after rotation
            print("\nAfter rotation %d:\n" % (i + 1))
            for j in range(n):
                print("%d " % a[j], end="")
            print("\n")

        # Print the first element of the final array a
        print("\nThe first element of the final array is: %d\n" % a[0])

if __name__ == "__main__":
    main()

