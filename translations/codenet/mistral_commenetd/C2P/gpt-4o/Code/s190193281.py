# Import necessary libraries
import sys

# Function to perform binary search on a sorted array
def binary_search(S, key):
    left, right = 0, len(S)  # Initialize left and right pointers
    while left < right:  # While the array is not yet searched completely
        mid = (left + right) // 2  # Calculate the middle index
        if S[mid] == key:
            return 1  # If key is found, return 1
        elif key < S[mid]:
            right = mid  # If key is smaller, search in left half
        else:
            left = mid + 1  # If key is greater, search in right half
    return 0  # If key is not present in the array, return 0

def main():
    # Read the size of the array
    n = int(input("Enter the size of the array: "))

    # Read the elements of the array
    S = []
    print(f"Enter {n} integers:")
    for i in range(n):
        element = int(input(f"Element {i + 1}: "))
        S.append(element)

    # Read the number of queries
    q = int(input("Enter the number of queries: "))

    # Read the queries
    T = []
    print(f"Enter {q} integers to be searched:")
    for i in range(q):
        query = int(input(f"Query {i + 1}: "))
        T.append(query)

    # Count the number of queries present in the array
    c = 0
    for query in T:
        if binary_search(S, query) == 1:
            c += 1

    # Print the number of queries present in the array
    print(f"Number of queries present in the array: {c}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
