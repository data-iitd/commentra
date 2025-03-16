
def calc_score():
    out = 0
    score = 0
    base = 0

    # Read the number of outs and update the score and base accordingly
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

if __name__ == "__main__":
    n = int(input())

    # Loop through each inning and calculate the score
    for _ in range(n):
        print(calc_score())

