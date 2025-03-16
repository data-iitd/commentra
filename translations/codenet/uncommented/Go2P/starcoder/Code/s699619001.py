D, G = map(int, input().split())
problems = []
for i in range(D):
    number, bonus = map(int, input().split())
    problems.append((number, bonus))

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
        while j >= 0:
            if bit & (1 << j) == 0:
                break
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

