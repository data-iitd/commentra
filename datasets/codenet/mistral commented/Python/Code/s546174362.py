N, M = map(int, input().split())
# Read the input: N (number of elements in the list A) and M (number of operations to perform)
A = list(map(int, input().split()))
# Read the list A
A = sorted(A)
# Sort the list A in ascending order

while M:
    A[-1] //= 2
    # Divide the last element of the list A by 2
    M -= 1
    # Decrement M by 1
    i = -2
    while M and (i >= len(A)-1 or A[i] >= A[-1]):
        # Check if we can perform the operation on the current element of the list A
        A[i] //= 2
        # Divide the current element by 2
        M -= 1
        # Decrement M by 1
        i -= 1
    A.sort()
    # Sort the list A in ascending order after each operation

print(sum(A))