import sys

def main():
    input_line = sys.stdin.readline().strip().split()
    m = int(input_line[1])
    s = int(input_line[2])
    f = int(input_line[3])
    maxT = -1
    map_ = {}
    
    while m > 0:
        mth = sys.stdin.readline().strip().split()
        k = int(mth[0])
        if k not in map_:
            map_[k] = []
        map_[k].append(int(mth[1]))
        map_[k].append(int(mth[2]))
        maxT = max(maxT, k)
        m -= 1
    
    actions = []
    M = 'R' if s < f else 'L'
    d = 1 if s < f else -1
    cur = s
    
    for t in range(1, maxT + 1):
        if t in map_:
            a, b = map_[t]
            if (cur >= a and cur <= b) or (cur + d >= a and cur + d <= b):
                actions.append('X')
            else:
                actions.append(M)
            cur += d
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
