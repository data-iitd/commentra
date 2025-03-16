# Read the values of N (total number of elements) and K (number of groups)
N, K = map(int, input().split())

# Initialize a list A with N elements, all set to 0
A = []
for i in range(N):
    A.append(0)

# Process each group
for i in range(K):
    # Read the size of the current group
    d = int(input())
    # Read the indices of the elements in the current group
    AA = list(map(int, input().split()))
    
    # Mark the elements in the list A as 1 for each index provided in the group
    for j in range(d):
        A[AA[j] - 1] = 1  # Subtract 1 to convert to 0-based index

# Count the number of elements that are still 0 in the list A
n = 0
for i in range(N):
    if A[i] == 0:
        n += 1  # Increment the count for each unmarked element

# Print the count of unmarked elements
print(n)
