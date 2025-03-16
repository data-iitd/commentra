
import math

def main():
    n, d = map(int, input().split())
    point = [[0 for _ in range(d + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        point[i] = list(map(int, input().split()))
    count = 0
    for i in range(1, n):
        for j in range(i + 1, n + 1):
            sum = 0
            for k in range(1, d + 1):
                sum += (point[i][k] - point[j][k]) ** 2
            kyori = math.sqrt(sum)
            if kyori.is_integer():
                count += 1
    print(count)

main()
