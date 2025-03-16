import sys

def main():
    INF = 100000
    D = int(input())
    G = int(input())
    p = []
    c = []
    for _ in range(D):
        pi, ci = map(int, input().split())
        p.append(pi)
        c.append(ci)
    
    min_solves = INF
    for bit in range(1 << D):
        score = 0
        solve_num = 0
        for i in range(D):
            if (bit & (1 << i)):
                score += 100 * (i + 1) * p[i] + c[i]
                solve_num += p[i]
        
        if score < G:
            for i in range(D - 1, -1, -1):
                if (bit & (1 << i)) == 0:
                    for _ in range(p[i] - 1):
                        score += 100 * (i + 1)
                        solve_num += 1
                        if score >= G:
                            break
            else:
                if score >= G:
                    min_solves = min(min_solves, solve_num)
    
    print(min_solves)

if __name__ == "__main__":
    main()
