# The code reads an integer N.
N = int(input())

# It then creates a list A where each element is the product of an integer input and N plus its index i, for i in range(N).
A = [int(input()) * N + i for i in range(N)]

# The list A is sorted.
A.sort()

# A counter cnt is initialized to 0.
cnt = 0

# The code then iterates over the elements of A, checking if the remainder when divided by N, when divided by 2, matches the remainder of the index i when divided by 2.
for i in range(N):
    d = (A[i] % N) % 2
    if d % 2 != i % 2:
        cnt += 1

# If they do not match, the counter cnt is incremented.

# Finally, the code prints the result of cnt divided by 2.
print(cnt // 2)
