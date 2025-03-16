
import sys
input = sys.stdin.readline

D = int(input())
G = int(input())
p = [0] * D
c = [0] * D
for i in range(D):
    p[i], c[i] = map(int, input().split())

INF = 100000
min_solve_num = INF
for bit in range(1 << D):
    score = 0
    solve_num = 0
    for i in range(D):
        if bit & (1 << i):
            score += 100 * (i + 1) * p[i] + c[i]
            solve_num += p[i]
    if score < G:
        for i in range(D - 1, -1, -1):
            if not (bit & (1 << i)):
                for j in range(p[i] - 1):
                    score += 100 * (i + 1)
                    solve_num += 1
                    if score >= G:
                        break
    if score >= G:
        min_solve_num = min(min_solve_num, solve_num)

print(min_solve_num)

