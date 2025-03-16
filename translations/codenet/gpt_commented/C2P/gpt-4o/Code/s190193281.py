N = 1000000  # Maximum size for the array S
Q = 50000    # Maximum size for the array T

n = int(input())  # Read the number of elements in the sorted array S
S = list(map(int, input().split()))  # Read the elements into the sorted array S

# Function to perform binary search on the sorted array S
def binary_search(key):
    left, right = 0, n  # Initialize left and right pointers for the search range
    while left < right:  # Continue searching while the range is valid
        mid = (left + right) // 2  # Calculate the middle index
        if S[mid] == key:
            return 1  # If the key is found, return 1
        elif key < S[mid]:
            right = mid  # Narrow the search to the left half
        else:
            left = mid + 1  # Narrow the search to the right half
    return 0  # If the key is not found, return 0

q = int(input())  # Read the number of queries
c = 0  # Count of found keys

# Process each query to check if it exists in the sorted array S
for _ in range(q):
    T = int(input())  # Read the query element
    if binary_search(T) == 1:  # If the element is found, increment the count
        c += 1

# Output the total count of found elements
print(c)

# <END-OF-CODE>
