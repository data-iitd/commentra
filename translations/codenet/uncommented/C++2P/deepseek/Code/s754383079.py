def main():
    a = input().strip()
    b = input().strip()
    n = len(a)
    m = len(b)
    ans = n + 10
    for i in range(n - m + 1):
        sum = 0
        for j in range(m):
            if a[i + j] != b[j]:
                sum += 1
        ans = min(ans, sum)
    print(ans)

main()
