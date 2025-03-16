
def search(A, n, key):
    i = 0
    # Add the key to the end of the array to handle the case where the key is not found
    A[n] = key
    # Loop until the key is found in the array
    while A[i]!= key: i += 1
    # Return 1 if the key is found, otherwise return 0
    return i!= n

n = int(input())
A = list(map(int, input().split()))
q = int(input())
sum = 0

for i in range(q):
    key = int(input())
    # Perform the search operation for the current query element
    if search(A, n, key): sum += 1

# Print the count of successful searches
print(sum)

