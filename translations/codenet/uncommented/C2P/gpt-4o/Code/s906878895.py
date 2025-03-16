import sys

for line in sys.stdin:
    a, b = map(int, line.split())
    x = a + b
    w = 0
    while x:
        w += 1
        x //= 10
    print(w)

# <END-OF-CODE>
