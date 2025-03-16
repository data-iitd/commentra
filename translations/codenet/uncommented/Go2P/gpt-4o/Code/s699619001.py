def min(a, b):
    return b if a >= b else a

def main():
    D, G = map(int, input().split())
    problems = []
    for _ in range(D):
        number, bonus = map(int, input().split())
        problems.append({'number': number, 'bonus': bonus})

    ans = 10000
    for bit in range(1 << D):
        score = 0
        solved = 0
        ok = False
        for j in range(D):
            if bit & (1 << j) != 0:
                score += (j + 1) * 100 * problems[j]['number'] + problems[j]['bonus']
                solved += problems[j]['number']
        
        if score < G:
            j = D - 1
            while j >= 0 and (bit & (1 << j)) != 0:
                j -= 1
            
            for k in range(problems[j]['number']):
                score += (j + 1) * 100
                solved += 1
                if score >= G:
                    ok = True
                    break
            
            if not ok:
                score += problems[j]['bonus']
                if score >= G:
                    ok = True
        else:
            ok = True
        
        if ok:
            ans = min(ans, solved)
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
