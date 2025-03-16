
import sys

def main():
    # Read the total number of levels
    n = int(input())

    # Read the number of levels the user has completed
    levels = int(input())

    # Initialize array to store completed levels
    arr = [0] * levels

    # Read the levels completed by the user
    for i in range(levels):
        arr[i] = int(input())

    # Read the number of levels the second user has completed
    level2 = int(input())

    # Calculate the total number of levels
    level3 = levels + level2

    # Initialize array to store all levels
    arr2 = [0] * level3

    # Copy levels from arr to arr2
    for i in range(levels):
        arr2[i] = arr[i]

    # Read additional levels for arr2
    for i in range(levels, level3):
        arr2[i] = int(input())

    # Generate a sequence of numbers from 1 to n
    arr3 = [0] * n
    j = 0
    for i in range(n):
        arr3[i] = j + 1
        j += 1

    # Check if all numbers from 1 to n are present in arr2
    count = 0
    for i in range(n):
        for x in range(level3):
            if arr3[i] == arr2[x]:
                count += 1
                break

    # Print the result based on whether all levels were completed
    if count == n:
        print("I become the guy.")
    else:
        print("Oh, my keyboard!")

if __name__ == "__main__":
    main()

