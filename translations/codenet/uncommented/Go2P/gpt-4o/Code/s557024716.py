import sys
from itertools import product

def main():
    a, b, c = map(int, sys.stdin.readline().split())
    k = int(sys.stdin.readline().strip())

    patterns = product([0, 1, 2, 3], repeat=k)

    for P in patterns:
        r, g, b = a, b, c
        for i in range(len(P)):
            if P[i] == 0:
                continue
            elif P[i] == 1:
                r *= 2
            elif P[i] == 2:
                g *= 2
            elif P[i] == 3:
                b *= 2

        if g > r and b > g:
            print("Yes")
            return

    print("No")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
