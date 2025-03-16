
import sys

D = int(input())
G = int(input())
p = [0] * D
c = [0] * D
for i in range(D):
    p[i], c[i] = map(int, input().split())

min_num = sys.maxsize
for bit in range(1 << D):
    score = 0
    solve_num = 0
    for i in range(D):
        if (bit >> i) & 1:
            score += 100 * (i + 1) * p[i] + c[i]
            solve_num += p[i]
    if score < G:
        for i in range(D - 1, -1, -1):
            if (bit >> i) & 1 == 0:
                for j in range(p[i] - 1):
                    score += 100 * (i + 1)
                    solve_num += 1
                    if score >= G:
                        break
                else:
                    continue
                break
    if score >= G:
        min_num = min(min_num, solve_num)

print(min_num)

