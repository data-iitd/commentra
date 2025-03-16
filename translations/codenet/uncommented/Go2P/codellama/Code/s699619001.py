
import sys

def min(a, b):
    if a >= b:
        return b
    return a

def main():
    D, G = map(int, sys.stdin.readline().split())
    problems = []
    for i in range(D):
        number, bonus = map(int, sys.stdin.readline().split())
        problems.append(problem(number, bonus))
    # print("D", D, "G", G, "problems", problems)

    ans = 10000
    for bit in range(1 << D):
        score = 0
        solved = 0
        ok = False
        for j in range(D):
            if bit & (1 << j) != 0:
                score += (j+1)*100*problems[j].number + problems[j].bonus
                solved += problems[j].number
        if score < G:
            j = D - 1
            for j in range(D-1, -1, -1):
                if bit & (1 << j) == 0:
                    break
            for k in range(problems[j].number):
                score += (j + 1) * 100
                solved += 1
                if score >= G:
                    ok = True
                    break
            if not ok:
                score += problems[j].bonus
                if score >= G:
                    ok = True
        else:
            ok = True
        if ok:
            ans = min(ans, solved)
    print(ans)


class problem:
    def __init__(self, number, bonus):
        self.number = number
        self.bonus = bonus


if __name__ == "__main__":
    main()


