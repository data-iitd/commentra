import sys

def main():
    D = int(sys.stdin.readline())
    G = int(sys.stdin.readline())
    p = [0] * D
    c = [0] * D
    for i in range(D):
        p[i], c[i] = map(int, sys.stdin.readline().split())
    min = 100000
    for bit in range(1 << D):
        score = 0
        solve_num = 0
        for i in range(D):
            if (bit & (1 << i))!= 0:
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
            min = min if min < solve_num else solve_num
    print(min)

if __name__ == "__main__":
    main()

