import sys
from functools import cmp_to_key

# Function to compare two integers for sorting
def compare(a, b):
    # Return the difference between b and a for descending order
    return b - a

def main():
    # Declare an array of integers
    array = []

    # Read 10 integers from standard input into the array
    for _ in range(10):
        array.append(int(sys.stdin.readline().strip()))

    # Sort the array in descending order using the compare function
    array.sort(key=cmp_to_key(compare))

    # Print the first 3 elements of the sorted array
    for i in range(3):
        print(array[i])

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
