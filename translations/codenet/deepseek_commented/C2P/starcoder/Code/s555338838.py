
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
    # Step 1: Read the length of the array
    len = int(input())

    # Step 2: Read the elements of the array
    a = [int(x) for x in input().split()]

    # Step 3: Perform Insertion Sort
    insertion_sort(a)

    # Step 4: Print the sorted array
    for i in range(len):
        print(a[i], end = " ")
    print()

if __name__ == "__main__":
    main()

