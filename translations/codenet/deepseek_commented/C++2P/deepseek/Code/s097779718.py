def euclid(x, y):
    while y != 0:
        x, y = y, x % y
    return x

def main():
    A, B = map(int, input().split())
    print((A * B) // euclid(A, B))

main()
