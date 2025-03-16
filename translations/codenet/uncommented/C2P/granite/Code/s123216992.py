
def swap(a, b):
    tmp = a
    a = b
    b = tmp

while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0:
        break
    if b < a:
        swap(a, b)
    print(a, b)

