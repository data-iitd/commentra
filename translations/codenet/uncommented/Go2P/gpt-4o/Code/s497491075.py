import sys
import math

def run(r, w):
    lines = r.read().strip().splitlines()
    a = list(map(int, lines[0].split()))
    N, D = a[0], a[1]

    count = 0
    for i in range(1, N + 1):
        line = list(map(int, lines[i].split()))
        d = math.sqrt(line[0] ** 2 + line[1] ** 2)
        if D >= d:
            count += 1

    w.write(f"{count}\n")

if __name__ == "__main__":
    run(sys.stdin, sys.stdout)

# <END-OF-CODE>
