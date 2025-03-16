def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    D = int(data[0])
    G = int(data[1])
    p = []
    c = []
    
    index = 2
    for i in range(D):
        p.append(int(data[index]))
        c.append(int(data[index + 1]))
        index += 2
    
    INF = 100000
    min_solve_num = INF
    
    for bit in range(1 << D):
        score = 0
        solve_num = 0
        
        for i in range(D):
            if (bit & (1 << i)) != 0:
                score += 100 * (i + 1) * p[i] + c[i]
                solve_num += p[i]
        
        if score < G:
            for i in range(D - 1, -1, -1):
                if (bit & (1 << i)) == 0:
                    for j in range(p[i] - 1):
                        score += 100 * (i + 1)
                        solve_num += 1
                        if score >= G:
                            break
                if score >= G:
                    break
        
        if score >= G:
            min_solve_num = min(min_solve_num, solve_num)
    
    print(min_solve_num)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
