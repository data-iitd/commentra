# <START-OF-CODE>
import sys

def main():
    N = int(raw_input())
    A = map(int, raw_input().split())

    answer = 0
    for i in xrange(N - 1):
        for j in xrange(i + 1, N):
            diff = abs(A[i] - A[j])
            answer = max(answer, diff)
    print answer

if __name__ == '__main__':
    main()
# 