def main():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()

    for i in range(n - 1):
        if a[i + 1] < 2 * a[i] and a[i] != a[i + 1]:
            print("YES")
            return

    print("NO")


if __name__ == "__main__":
    main()

