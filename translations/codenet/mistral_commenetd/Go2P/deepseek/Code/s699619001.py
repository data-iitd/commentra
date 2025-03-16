def min(a, b):
    return b if a >= b else a

def main():
    D, G = map(int, input().split())
    problems = []
    for _ in range(D):
        number, bonus = map(int, input().split())
        problems.append((number, bonus))
    
    ans = 10000
    
    for bit in range(1 << D):
        score = 0
        solved = 0
        ok = False
        
        for j in range(D):
            if bit & (1 << j):
                score += (j + 1) * 100 * problems[j][0] + problems[j][1]
                solved += problems[j][0]
        
        if score < G:
            for j in range(D - 1, -1, -1):
                if not bit & (1 << j):
                    for k in range(problems[j][0]):
                        score += (j + 1) * 100
                        solved += 1
                        if score >= G:
                            ok = True
                            break
                    if ok:
                        break
                    if problems[j][1] > 0:
                        score += problems[j][1]
                        solved += 1
                        if score >= G:
                            ok = True
                            break
                if ok:
                    break
        else:
            ok = True
        
        if ok:
            ans = min(ans, solved)
    
    print(ans)

main()
