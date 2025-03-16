def euclid(x, y):
    if x < y:
        x, y = y, x

    if x % y == 0:
        return y
    return euclid(y, x % y)

A, B = map(int, input().split())
print((A * B) // euclid(A, B))

# <END-OF-CODE>
