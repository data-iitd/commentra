
# <START-OF-CODE>

import sys

def main():
    s = sys.stdin.readline().strip()
    targ = list(s)
    map = {}
    for c in targ:
        if c not in map:
            map[c] = 1
        else:
            map[c] += 1
    ok = True
    for c in map:
        if map[c]!= 2:
            ok = False
            break
    if ok and len(map) == 2:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# 