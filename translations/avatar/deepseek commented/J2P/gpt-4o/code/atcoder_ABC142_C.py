# Importing the necessary module
from collections import defaultdict

def main():
    # Step 1: Read the input value N, which represents the number of elements.
    N = int(input())

    # Step 2: Create a dictionary idorder to store the elements and their corresponding positions.
    idorder = {}

    # Step 3: Read each element and store its value and position in the dictionary.
    for i in range(1, N + 1):
        A = int(input())
        idorder[A] = i

    # Step 4: Print the positions of the elements in the order they were read.
    for i in range(1, N + 1):
        print(idorder.get(i), end=" ")

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
