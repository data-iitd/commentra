
def you(x, y):
    z = x % y
    while y > 0:
        x = y
        y = z
        z = x % y
    return x

x = int(input())
y = int(input())
if x >= y:
    z = you(x, y)
else:
    z = you(y, x)
print(z)

