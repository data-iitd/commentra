# Declare a list A to hold up to 1,000,000 integers and a variable n for the number of elements
A = []
n = 0

# Binary Search function
def binary_search(key):
    left = 0  # Initialize the left boundary of the search range
    right = n  # Initialize the right boundary of the search range

    # Continue searching while the left boundary is less than the right boundary
    while left < right:
        mid = (left + right) // 2  # Calculate the midpoint index
        if key == A[mid]: 
            return 1  # If the key is found, return 1
        if key > A[mid]: 
            left = mid + 1  # If the key is greater, search in the right half
        else: 
            right = mid  # If the key is smaller, search in the left half
    return 0  # If the key is not found, return 0

# Main function
if __name__ == "__main__":
    # Read the number of elements in the array
    n = int(input())
    
    # Read the elements into the list A
    A = list(map(int, input().split()))

    # Read the number of queries
    q = int(input())
    
    sum_found = 0  # Initialize a sum counter

    # Process each query
    for _ in range(q):
        k = int(input())  # Read the key to search for
        if binary_search(k):  # Perform binary search for the key
            sum_found += 1  # Increment the sum if the key is found

    # Output the total number of keys found in the array
    print(sum_found)

# <END-OF-CODE>
