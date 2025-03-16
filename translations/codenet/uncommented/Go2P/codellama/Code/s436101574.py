
import sys

def scanString():
    return sys.stdin.readline().strip()

def scanRunes():
    return list(scanString())

def scanInt():
    return int(scanString())

def scanInt64():
    return int(scanString())

def scanFloat64():
    return float(scanString())

def scanInts(n):
    return [int(x) for x in sys.stdin.readline().split()]

def debug(*a):
    print(*a)

def abs(a):
    if a < 0:
        return -a
    return a

def min(a, b):
    if a < b:
        return a
    return b

def max(a, b):
    if a > b:
        return a
    return b

#•*¨*•.¸¸♪main•*¨*•.¸¸♪(　-ω-)ノ　(　・ω・)
def main():
    s = scanRunes()
    t = scanRunes()

    ans = []
    for i in range(len(s) - len(t) + 1):
        f = True
        ss = list(s)

        for j in range(len(t)):
            if s[i+j] != t[j] and s[i+j] != '?':
                f = False
                break
            else:
                ss[i+j] = t[j]

        if f:
            ans.append(''.join(ss).replace('?', 'a'))

    ans.sort()
    if len(ans) == 0:
        print("UNRESTORABLE")
    else:
        print(ans[0])

if __name__ == '__main__':
    main()

