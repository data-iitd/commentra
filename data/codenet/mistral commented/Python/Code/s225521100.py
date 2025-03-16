
N, K = map(int, input().split())
# Define N and K as integers, where N is the size of the list and K is the number of queries.

A = []
# Initialize an empty list A of size N.

for i in range(N):
    A.append(0)
# Iterate through the range of N and append 0 to each index of list A.

for i in range(K):
    d = int(input())
    # Take the first input as an integer d, which represents the number of indices to be updated.
    AA = list(map(int, input().split()))
    # Take the second input as a list AA, which contains the indices to be updated.
    for j in range(d):
        A[AA[j] - 1] = 1
    # Iterate through the range of d and update the value of the corresponding index in list A to 1.

n = 0
# Initialize a variable n with a value of 0.

for i in range(N):
    if A[i] == 0:
        n += 1
# Iterate through the range of N and increment the value of n if the index i in list A is 0.

print(n)
# Print the value of the variable n.