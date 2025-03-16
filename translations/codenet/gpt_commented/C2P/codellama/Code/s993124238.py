#include <stdio.h>
#include <math.h>

def main():
    n, d = map(int, input().split())
    point = [[0] * (d + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, d + 1):
            point[i][j] = int(input())
    count = 0
    for i in range(1, n - 1):
        for j in range(i + 1, n + 1):
            sum = 0
            for k in range(1, d + 1):
                sum += (point[i][k] - point[j][k]) ** 2
            kyori = sqrt(sum)
            if ceil(kyori) == floor(kyori):
                count += 1
    print(count)


