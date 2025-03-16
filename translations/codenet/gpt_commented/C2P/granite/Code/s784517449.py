
# Python code

# Read the number of elements in the array
n = int(input())

# Read the elements into the array A
A = list(map(int, input().split()))

# Read the number of queries
q = int(input())

# Process each query
sum = 0
for i in range(q):
    k = int(input()) # Read the key to search for
    if k in A: # Check if the key is in the array
        sum += 1 # Increment the sum if the key is found

# Output the total number of keys found in the array
print(sum)

