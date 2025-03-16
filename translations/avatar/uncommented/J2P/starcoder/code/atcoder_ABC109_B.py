
# <START-OF-CODE>

import sys

def main():
    N = int(sys.stdin.readline())
    map = {}
    for i in range(N):
        map[i] = sys.stdin.readline().strip()
    ans = True
    past = {}
    next = ""
    for i in range(N):
        if past.get(map[i], None) is not None:
            ans = False
            break
        past[i] = map[i]
        if i!= 0:
            if next!= map[i][0]:
                ans = False
                break
        next = map[i][-1]
    if ans:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

# 