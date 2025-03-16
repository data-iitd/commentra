def calc_score():
    out = 0
    score = 0
    base = 0

    # Read the number of outs and update the score and base accordingly
    while out < 3:
        str_input = input()
        if str_input == "OUT":
            out += 1
        elif str_input == "HIT":
            if base == 3:
                score += 1
            else:
                base += 1
        elif str_input == "HOMERUN":
            score += (base + 1)
            base = 0

    return score

def main():
    n = int(input())

    # Loop through each inning and calculate the score
    for _ in range(n):
        print(calc_score())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
