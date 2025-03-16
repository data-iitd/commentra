import sys
from collections import defaultdict

def main():
    input_data = sys.stdin.read().strip().split()
    m = int(input_data[1])
    s = int(input_data[2])
    f = int(input_data[3])
    maxT = -1
    map = defaultdict(list)

    for _ in range(m):
        mth = list(map(int, sys.stdin.readline().strip().split()))
        k = mth[0]
        map[k].append(mth[1])
        map[k].append(mth[2])
        maxT = max(maxT, k)

    actions = []
    M = 'R' if s < f else 'L'
    d = 1 if s < f else -1
    cur = s
    a = -1
    b = -1

    for t in range(1, maxT + 1):
        if t in map:
            a = map[t][0]
            b = map[t][1]
        
        if t in map and ((cur >= a and cur <= b) or (cur + d >= a and cur + d <= b)):
            actions.append('X')
        else:
            actions.append(M)
            cur += d
        
        if cur == f:
            break

    while cur != f:
        actions.append(M)
        cur += d

    print(''.join(actions))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
