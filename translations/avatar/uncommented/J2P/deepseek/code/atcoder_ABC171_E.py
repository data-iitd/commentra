def main():
    n = int(input())
    a = list(map(int, input().split()))
    r = 0
    for i in range(n):
        r ^= a[i]
    result = []
    for i in range(n):
        result.append(str(r ^ a[i]))
    print(" ".join(result))

if __name__ == "__main__":
    main()
