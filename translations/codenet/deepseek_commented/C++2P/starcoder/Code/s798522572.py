
# Python 3.6.1
# Author: <NAME>
# Date: 2017-09-12

# <START-OF-CODE>

import sys

def main():
    N, T = map(int, input().split())
    A = list(map(int, input().split()))
    B = [A[1] - A[0]]
    m = A[0]
    for i in range(2, N):
        B.append(A[i] - m)
        m = min(m, A[i])
    print(max(B))
    print(B.count(max(B)))

if __name__ == '__main__':
    main()

# 