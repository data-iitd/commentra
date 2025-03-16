# Importing the necessary module for reading input
import sys

def main():
    # Reading the number of elements in the list from the standard input
    n = int(sys.stdin.readline().strip())

    # Creating an empty list to store the elements
    lst = []

    # Iterating through the input to add each element to the list
    for _ in range(n):
        lst.append(int(sys.stdin.readline().strip()))

    # Creating an empty list to store odd numbers
    odd = []
    total_sum = 0  # Initializing the sum variable to 0

    # Iterating through each element in the list
    for i in lst:
        if i % 2 == 0:  # Checking if the current element is even
            total_sum += i  # Adding the even number to the sum
        else:
            odd.append(i)  # Adding the odd number to the odd list

    # Sorting the odd list in ascending order
    odd.sort()

    # Iterating through each odd number in the sorted odd list
    for i in odd:
        total_sum += i  # Adding the odd number to the sum

    # Checking if the size of the odd list is odd
    if len(odd) % 2 != 0:
        total_sum -= odd[0]  # Subtracting the first odd number if the size is odd

    # Printing the final sum to the standard output
    print(total_sum)

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
