
# Python code to perform binary search on a sorted array

# Define the binary search function
def binary_search(S, key):
    left = 0
    right = len(S) - 1
    while left <= right:
        mid = (left + right) // 2
        if S[mid] == key:
            return True
        elif key < S[mid]:
            right = mid - 1
        else:
            left = mid + 1
    return False

# Read the number of elements in the sorted array S
n = int(input("Enter the number of elements in the sorted array S: "))

# Read the elements into the sorted array S
S = [int(input("Enter element S[" + str(i) + "]: ")) for i in range(n)]

# Sort the array S
S.sort()

# Read the number of queries
q = int(input("Enter the number of queries: "))

# Process each query to check if it exists in the sorted array S
c = 0
for i in range(q):
    T = int(input("Enter query element T[" + str(i) + "]: "))
    if binary_search(S, T):
        c += 1

# Output the total count of found elements
print("Total count of found elements:", c)

