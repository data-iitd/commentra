# Import necessary libraries
import sys
from itertools import product

# Type definitions for convenience
INF = 1000000000
MOD = 1000000007
EPS = 0.00000001

def main():
    # Input the sizes of the three arrays and the number K
    X, Y, Z, K = map(int, input().split())

    # Read values into list A
    A = list(map(int, input().split()))

    # Read values into list B
    B = list(map(int, input().split()))

    # Read values into list C
    C = list(map(int, input().split()))

    # Sort the lists in descending order to facilitate maximum sum calculations
    A.sort(reverse=True)
    B.sort(reverse=True)
    C.sort(reverse=True)

    # Create a list to store the sums of elements from A and B
    AB = []

    # Calculate all possible sums of elements from A and B
    for a in A:
        for b in B:
            AB.append(a + b)

    # Sort the sums in descending order
    AB.sort(reverse=True)

    # Create a list to store the final sums including elements from C
    ABC = []

    # Calculate sums of the top K elements from AB with each element from C
    for i in range(min(K, len(AB))):
        for c in C:
            ABC.append(AB[i] + c)

    # Sort the final sums in descending order
    ABC.sort(reverse=True)

    # Output the top K sums from the final list
    for i in range(K):
        print(ABC[i])

if __name__ == "__main__":
    main()

# <END-OF-CODE>
