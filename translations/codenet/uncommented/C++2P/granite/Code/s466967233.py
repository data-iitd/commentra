
import sys

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = [-1] * (N + 1)
    now = 1
    cnt = 0
    B[1] = 0
    for j in range(1, K + 1):
        now = A[now - 1]
        if B[now] == -1:
            B[now] = j
        else:
            cnt = j
            break
    if j < K:
        tmp = (K - B[now]) % (cnt - B[now])
        for j in range(tmp):
            now = A[now - 1]
    print(now)

if __name__ == "__main__":
    main()

