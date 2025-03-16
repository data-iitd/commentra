def main():
    while True:
        n, r = map(int, input().split())
        if n == 0 and r == 0:
            break

        a = list(range(1, n + 1))

        for _ in range(r):
            p, c = map(int, input().split())

            b = a[n - p - c + 1:n - p + 1]
            a[n - p - c + 1:n - p + 1] = a[n - p + 1:n + 1]
            a[n - p + 1:n - p + 1 + c] = b

        print(a[n - 1])

if __name__ == "__main__":
    main()
# <END-OF-CODE>
