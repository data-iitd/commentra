import sys

def main():
    # Reading input from stdin
    h, w, n = map(int, sys.stdin.readline().split())
    sr, sc = map(int, sys.stdin.readline().split())
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()

    # Initializing boundaries of the safe zone
    usafe, dsafe = 1, h
    lsafe, rsafe = 1, w

    # Checking vertical boundaries of the safe zone
    for i in range(n - 1, -1, -1):
        if s[i] == 'U':
            usafe += 1
        elif s[i] == 'D':
            dsafe -= 1
        if usafe > dsafe:
            print("NO")
            return
        if i > 0:
            if t[i - 1] == 'U':
                dsafe = min(dsafe + 1, h)
            elif t[i - 1] == 'D':
                usafe = max(usafe - 1, 1)

    # Checking horizontal boundaries of the safe zone
    for i in range(n - 1, -1, -1):
        if s[i] == 'L':
            lsafe += 1
        elif s[i] == 'R':
            rsafe -= 1
        if lsafe > rsafe:
            print("NO")
            return
        if i > 0:
            if t[i - 1] == 'L':
                rsafe = min(rsafe + 1, w)
            elif t[i - 1] == 'R':
                lsafe = max(lsafe - 1, 1)

    # Checking if the starting position is within the safe zone
    if sr >= usafe and sr <= dsafe and sc >= lsafe and sc <= rsafe:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
