
import math
import sys

def main():
    N, D = map(int, sys.stdin.readline().split())
    matrix = []
    for i in range(N):
        matrix.append(list(map(int, sys.stdin.readline().split())))
    k = 0
    for i in range(N - 1):
        for j in range(i + 1, N):
            m = 0
            for n in range(D):
                m = (matrix[i][n] - matrix[j][n]) * (matrix[i][n] - matrix[j][n]) + m
            l = math.sqrt(m)
            if math.ceil(l) == math.floor(l):
                k += 1
    print(k)

if __name__ == "__main__":
    main()

