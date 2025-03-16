
# <START-OF-CODE>

def isValid(s1, s2):
    if len(s1)!= len(s2):
        return False
    for c in s1:
        if c not in s2:
            return False
    return True

def main():
    s1 = input()
    s2 = input()
    if isValid(s1, s2):
        m1 = {}
        m2 = {}
        for c in s1:
            if c in m1:
                m1[c] += 1
            else:
                m1[c] = 1
        for c in s2:
            if c in m2:
                m2[c] += 1
            else:
                m2[c] = 1
        ans = 0
        hs = set()
        for c in s2:
            if c not in hs:
                hs.add(c)
                x1 = m1[c]
                x2 = m2[c]
                x1 = min(x1, x2)
                ans += x1
        print(ans)
    else:
        print(-1)

main()

# 