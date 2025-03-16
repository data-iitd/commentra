def gcd(x, y):
    while True:
        z = x % y
        x = y
        y = z
        if y <= 0:
            break
    return x

def main():
    x, y = map(int, input().split())
    if x >= y:
        z = gcd(x, y)
    else:
        z = gcd(y, x)
    print(z)

main()
