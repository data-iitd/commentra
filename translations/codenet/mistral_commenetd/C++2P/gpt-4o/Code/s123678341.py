# Import necessary libraries
import sys
from itertools import product

# Main function starts here
def main():
    # Initialize input variables
    X, Y, Z, K = map(int, input().split())  # Read input values for X, Y, Z, and K from standard input

    # Initialize lists A, B, and C
    A = list(map(int, input().split()))  # Read each element of vector A
    B = list(map(int, input().split()))  # Read each element of vector B
    C = list(map(int, input().split()))  # Read each element of vector C

    # Sort lists A, B, and C in descending order
    A.sort(reverse=True)
    B.sort(reverse=True)
    C.sort(reverse=True)

    # Create a new list AB by adding each element of A to each element of B
    AB = [a + b for a, b in product(A, B)]  # Use product to combine A and B
    AB.sort(reverse=True)  # Sort AB in descending order

    # Create a new list ABC by adding each element of AB to each element of C
    ABC = []
    for i in range(min(K, len(AB))):
        for c in C:
            ABC.append(AB[i] + c)  # Add AB[i] and C[j] and push the sum into list ABC

    # Sort list ABC in descending order
    ABC.sort(reverse=True)

    # Print K smallest elements of list ABC
    for i in range(K):
        print(ABC[i])  # Print each element of list ABC

# Main function ends here
if __name__ == "__main__":
    main()

# <END-OF-CODE>
