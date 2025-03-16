# Importing the necessary module
import sys

def main():
    # Reading the first integer input 'n'
    n = int(input())
    # Reading the second integer input 'levels'
    levels = int(input())

    # Initializing sum variables
    sum1 = 0
    sum2 = 0
    sum3 = 0
    # Creating a list 'arr' of size 'levels'
    arr = [0] * levels

    # Loop to read 'levels' number of integers and store them in 'arr'
    for i in range(levels):
        arr[i] = int(input())

    # Reading the third integer input 'level2'
    level2 = int(input())
    # Calculating the size of 'arr2'
    level3 = levels + level2
    # Creating a list 'arr2' of size 'level3'
    arr2 = [0] * level3

    # Loop to copy elements of 'arr' to 'arr2'
    for i in range(len(arr)):
        arr2[i] = arr[i]

    # Loop to read 'level2' number of integers and store them in 'arr2'
    for i in range(len(arr), level3):
        arr2[i] = int(input())

    # Creating a list 'arr3' of size 'n'
    arr3 = [0] * n
    # Initializing 'j' variable to 0
    j = 0

    # Loop to initialize 'arr3' with numbers from 1 to 'n'
    for i in range(n):
        j += 1
        arr3[i] = j

    # Initializing count variable to 0
    count = 0

    # Outer loop to compare each element of 'arr3' with 'arr2'
    for i in range(n):
        for x in range(len(arr2)):
            # If a match is found
            if arr3[i] == arr2[x]:
                count += 1  # Increment the count variable
                break  # Exit the inner loop

    # If all elements of 'arr3' are present in 'arr2'
    if count == n:
        print("I become the guy.")  # Print the message
    else:
        print("Oh, my keyboard!")  # Print the error message

# Calling the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
