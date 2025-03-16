import sys

SIZE = (10**5 * 2) + 13

a = []
cnt = [0] * SIZE

def main():
    n, k = map(int, sys.stdin.readline().split())
    for _ in range(n):
        x = int(sys.stdin.readline())
        cnt[x] += 1
    for i in range(len(cnt)):
        if cnt[i] > 0:
            a.append(cnt[i])
    a.sort()
    m = len(a) - k
    ans = sum(a[:m])
    print(ans)

main()
