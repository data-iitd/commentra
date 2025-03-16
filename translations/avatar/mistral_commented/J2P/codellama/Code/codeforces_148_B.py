import math

def main():
    VP = float(input())
    VD = float(input())
    T = float(input())
    F = float(input())
    C = float(input())

    if VD <= VP:
        print(0)
        return

    answer = 0
    start = T

    while True:
        x = start * VP / (VD - VP)

        if (start + x) * VP >= C:
            break

        start += 2 * x + F
        answer += 1

    print(answer)

main()

