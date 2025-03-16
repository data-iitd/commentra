
# <START-OF-CODE>
import sys

def main():
    N,K = map(int,input().split())
    A = [0]
    for i in range(N):
        A.append(int(input()))
    B = [-1] * 200100
    B[1] = 0
    now = 1
    cnt = 0
    for j in range(1,K+1):
        now = A[now]
        if B[now] == -1:
            B[now] = j
        else:
            cnt = j
            break
    if j < K:
        tmp = (K - B[now]) % (cnt - B[now])
        for j in range(tmp):
            now = A[now]
    print(now)

if __name__ == '__main__':
    main()
# 