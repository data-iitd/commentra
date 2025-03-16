# Importing the necessary module for user input
from collections import defaultdict

def main():  # Main function declaration
    N = int(input())  # Reading the number of elements from user input

    idorder = {}  # Declaring and initializing a dictionary 'idorder'

    # Reading the elements and storing their corresponding indices in the dictionary
    for i in range(1, N + 1):
        A = int(input())  # Reading an element 'A' from user input
        idorder[A] = i  # Storing the index 'i' of the element 'A' in the dictionary

    # Printing the indices of the elements in the order they were read
    for i in range(1, N + 1):
        print(idorder.get(i), end=" ")  # Printing the index of the current element

if __name__ == "__main__":
    main()  # Calling the main function

# <END-OF-CODE>
