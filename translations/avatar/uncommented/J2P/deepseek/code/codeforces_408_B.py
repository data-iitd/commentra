from collections import defaultdict, Counter

def isValid(s1, s2):
    map_char = defaultdict(bool)
    for c in s1:
        map_char[c] = True
    for c in s2:
        if c not in map_char:
            return False
    return True

def main():
    s1 = input().strip()
    s2 = input().strip()
    if not isValid(s1, s2):
        print(-1)
    else:
        counter1 = Counter(s1)
        counter2 = Counter(s2)
        ans = 0
        hs = set()
        for c in s2:
            if c not in hs:
                hs.add(c)
                x1 = counter1[c]
                x2 = counter2[c]
                x1 = min(x1, x2)
                ans += x1
        print(ans)

if __name__ == "__main__":
    main()
