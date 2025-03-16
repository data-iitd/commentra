
def you(x, y):
    while True:
        z = x % y
        x = y
        y = z
        if y <= 0:
            break
    return x

x, y = map(int, input().split())
if x >= y:
    z = you(x, y)
else:
    z = you(y, x)
print(z)

