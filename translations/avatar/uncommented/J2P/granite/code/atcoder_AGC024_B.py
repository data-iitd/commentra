
import sys

def main():
    N = int(input())
    P = list(map(int, input().split()))
    P = [p - 1 for p in P]
    pos = [0] * N
    for i, p in enumerate(P):
        pos[p] = i
    nglist = []
    for i in range(N - 1):
        if pos[i] > pos[i + 1]:
            nglist.append(i)
    if not nglist:
        print(0)
        return
    ans = min(N - nglist[0] - 1, nglist[-1] + 1)
    for i in range(len(nglist) - 1):
        ans = min(nglist[i] + 1 + N - nglist[i + 1] - 1, ans)
    print(ans)

if __name__ == '__main__':
    main()

