#include <string.h>
#include <stdio.h>

def calc_score():
    out = 0
    str = ""
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

n = int(input())
inning = 0

# Loop through each inning and calculate the score
while inning < n:
    print(calc_score())
    inning += 1

# 