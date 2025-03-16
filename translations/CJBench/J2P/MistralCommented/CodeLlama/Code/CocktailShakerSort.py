
import sys

def main():
    # Read the number of elements in the array from the user input
    n = int(sys.stdin.readline().strip())

    # Allocate memory for an array of Integer type with the given size
    array = [None] * n

    # Read each element of the array from the user input
    for i in range(n):
        array[i] = int(sys.stdin.readline().strip())

    # Create an instance of the Main class and call the sort method to sort the array
    sorter = Main()
    sorter.sort(array)

    # Print each element of the sorted array to the console
    for num in array:
        print(num, end=" ")

    # End of code
    print("