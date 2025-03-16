def main():
    while True:
        n, r = map(int, input().split())
        if n == 0 and r == 0:
            break

        a = list(range(1, n + 1))

        for _ in range(r):
            p, c = map(int, input().split())
            b = a[-p:]
            a = a[:-p] + a[-p-c:-p]
            a = a[:-c] + b

        print(a[-1])

if __name__ == "__main__":
    main()
