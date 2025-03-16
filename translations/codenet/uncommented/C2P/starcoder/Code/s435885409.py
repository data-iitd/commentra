
def calc_score():
    out = 0
    score = 0
    base = 0
    while out < 3:
        str = input()
        if str == "OUT":
            out += 1
        elif str == "HIT":
            if base == 3:
                score += 1
            else:
                base += 1
        elif str == "HOMERUN":
            score += (base + 1)
            base = 0
    return score

def main():
    n = int(input())
    inning = 0
    while inning < n:
        print(calc_score())
        inning += 1

main()

