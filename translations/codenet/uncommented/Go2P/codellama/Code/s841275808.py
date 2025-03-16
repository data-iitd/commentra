
import sys

def main():
    N = int(sys.stdin.readline())
    X = [int(sys.stdin.readline()) for _ in range(N)]
    Y = X[:]
    Y.sort()
    m1 = Y[N // 2 - 1]
    m2 = Y[N // 2]
    for i in range(N):
        if X[i] <= m1:
            print(m2)
        else:
            print(m1)

if __name__ == "__main__":
    main()

