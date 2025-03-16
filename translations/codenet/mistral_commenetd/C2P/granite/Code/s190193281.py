

# Python code to perform binary search on an array

# Function to perform binary search on an array
def binarySearch(arr, key):
  left = 0
  right = len(arr) - 1
  while left <= right:
    mid = (left + right) // 2
    if arr[mid] == key:
      return True
    elif arr[mid] < key:
      left = mid + 1
    else:
      right = mid - 1
  return False

# Read the size of the array
n = int(input("Enter the size of the array: "))

# Read the elements of the array
S = [int(input(f"Element {i+1}: ")) for i in range(n)]

# Read the number of queries
q = int(input("Enter the number of queries: "))

# Read the queries
T = [int(input(f"Query {i+1}: ")) for i in range(q)]

# Initialize the count of queries present in the array
c = 0

# Perform binary search on each query and increment the count if the query is present in the array
for query in T:
  if binarySearch(S, query):
    c += 1

# Print the number of queries present in the array
print(f"Number of queries present in the array: {c}")

