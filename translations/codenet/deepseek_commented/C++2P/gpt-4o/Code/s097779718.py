def euclid(x, y):
    # Ensure x is greater than y
    if x < y:
        x, y = y, x

    # Base case: if x is divisible by y, return y
    if x % y == 0:
        return y

    # Recursive case: apply the Euclidean algorithm
    return euclid(y, x % y)

# Read two integers from standard input
A, B = map(int, input().split())

# Calculate and output the least common multiple (LCM) of A and B
print((A * B) // euclid(A, B))

# <END-OF-CODE>
