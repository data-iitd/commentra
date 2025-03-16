import math
import sys

def main():
    N, D = map(int, sys.stdin.readline().split())
    matrix = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
    k = 0
    
    for i in range(N - 1):
        for j in range(i + 1, N):
            m = 0
            for n in range(D):
                m += (matrix[i][n] - matrix[j][n]) ** 2
            l = math.sqrt(m)
            if math.ceil(l) == math.floor(l):
                k += 1
    
    print(k)

if __name__ == "__main__":
    main()
