
import sys

def main():
    N, M = map(int, input().split())
    H = list(map(int, input().split()))
    ans = [True] * N
    for _ in range(M):
        a, b = map(int, input().split())
        if H[a - 1] < H[b - 1]:
            ans[a - 1] = False
        elif H[a - 1] > H[b - 1]:
            ans[b - 1] = False
        else:
            ans[a - 1] = False
            ans[b - 1] = False
    print(sum(ans))

if __name__ == '__main__':
    main()

