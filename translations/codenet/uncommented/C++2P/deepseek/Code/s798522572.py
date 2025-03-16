import sys

def main():
    input = sys.stdin.readline
    N, T = map(int, input().split())
    A = list(map(int, input().split()))
    B = [0] * N
    m = A[0]
    B[1] = A[1] - m
    m = min(m, A[1])
    for i in range(2, N):
        B[i] = A[i] - m
        m = min(m, A[i])
    max_B = max(B)
    count = B.count(max_B)
    print(count)

if __name__ == "__main__":
    main()
