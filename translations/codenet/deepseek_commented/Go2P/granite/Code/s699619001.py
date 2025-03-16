
D, G = map(int, input().split())
problems = [tuple(map(int, input().split())) for _ in range(D)]

def min(a, b):
    if a >= b:
        return b
    return a

ans = 10000
for bit in range(1 << D):
    score = 0
    solved = 0
    ok = False
    for j in range(D):
        if bit & (1 << j)!= 0:
            score += (j + 1) * 100 * problems[j][0] + problems[j][1]
            solved += problems[j][0]
    if score < G:
        j = D - 1
        while bit & (1 << j)!= 0:
            j -= 1
        for k in range(problems[j][0]):
            score += (j + 1) * 100
            solved += 1
            if score >= G:
                ok = True
                break
        if not ok:
            score += problems[j][1]
            if score >= G:
                ok = True
    else:
        ok = True
    if ok:
        ans = min(ans, solved)
print(ans)

