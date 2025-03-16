import math
import sys

def main():
    N = int(input())
    D = int(input())
    vectors = []
    for i in range(N):
        vectors.append(list(map(int, input().split())))
    answer = 0
    for i in range(N-1):
        for j in range(i+1, N):
            dist = 0
            for d in range(D):
                x = (vectors[i][d] - vectors[j][d])
                dist += (x * x)
            sq = math.sqrt(dist)
            answer += (abs(sq - math.floor(sq)) < 0.001)
    print(answer)

if __name__ == "__main__":
    main()

