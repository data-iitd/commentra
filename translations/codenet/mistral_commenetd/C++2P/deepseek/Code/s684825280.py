SIZE = (10**5 * 2) + 13

a = []
cnt = [0] * SIZE

def main():
    n, k = map(int, input().split())

    for _ in range(n):
        x = int(input())
        cnt[x] += 1

    for i in range(len(cnt)):
        if cnt[i] > 0:
            a.append(cnt[i])

    ans = 0

    a.sort()

    m = len(a) - k

    for i in range(m):
        ans += a[i]

    print(ans)

main()
