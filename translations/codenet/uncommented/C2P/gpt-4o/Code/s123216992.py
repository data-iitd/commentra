def swap(a, b):
    return b, a

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    if b < a:
        a, b = swap(a, b)
    print(a, b)

# <END-OF-CODE>
