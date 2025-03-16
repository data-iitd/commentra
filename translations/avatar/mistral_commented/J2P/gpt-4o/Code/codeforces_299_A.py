# Importing the necessary modules
import sys

def main():
    n = int(input())  # Reading the number of elements in the array from the user input
    a = list(map(int, input().split()))  # Reading the array elements from user input

    a.sort()  # Sorting the array in ascending order

    min_value = a[0]  # Assigning the minimum value in the array to the min_value variable

    # Checking if all the elements in the array are multiples of the minimum value
    for value in a:
        if value % min_value != 0:  # Checking if the current element is not a multiple of the minimum value
            print(-1)  # Printing -1 if any non-multiple of the minimum value is found
            return  # Exiting the function if any non-multiple of the minimum value is found

    # Printing the minimum value if all elements are multiples of the minimum value
    print(min_value)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
