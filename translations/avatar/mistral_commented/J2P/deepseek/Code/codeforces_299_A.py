import sys

def main():
    # Reading the number of elements in the array from the standard input
    n = int(input().strip())
    # Reading the elements of the array from the standard input
    a = list(map(int, input().strip().split()))

    # Sorting the array in ascending order
    a.sort()

    # Assigning the minimum value in the array to the min variable
    min_val = a[0]

    # Checking if all the elements in the array are multiples of the minimum value
    for value in a:
        if value % min_val != 0:  # Checking if the current element is not a multiple of the minimum value
            print(-1)  # Printing -1 if any non-multiple of the minimum value is found
            return  # Exiting the method if any non-multiple of the minimum value is found

    # Printing the minimum value if all elements are multiples of the minimum value
    print(min_val)

# Calling the main method
if __name__ == "__main__":
    main()
