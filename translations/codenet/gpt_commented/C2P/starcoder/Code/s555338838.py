#include <stdio.h>

def insertion_sort(a):
    for j in range(1, len(a)):
        key = a[j]
        i = j - 1
        while i >= 0 and a[i] > key:
            a[i + 1] = a[i]
            i -= 1
        a[i + 1] = key

def main():
    # Declare variables
    a = []
    len = 0

    # Read the length of the array
    len = int(input())

    # Read the elements of the array
    for i in range(len):
        a.append(int(input()))

    # Perform insertion sort
    insertion_sort(a)

    # Print the sorted array
    for i in range(len):
        print(a[i], end = " ")
    print() # Move to the next line after printing the sorted array

if __name__ == "__main__":
    main()

