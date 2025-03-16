def max_left(n):
    return n - 2 if n > 2 else 0

t = int(input())
for _ in range(t):
    n = int(input())
    print(max_left(n))

# <END-OF-CODE>
