import sys
from collections import Counter

def isValid(s1, s2):
    for char in s1:
        if char not in s2:
            return False
    return True

def main():
    s1 = input().strip()
    s2 = input().strip()
    
    if not isValid(s1, s2):
        print(-1)
    else:
        m1 = Counter(s1)
        m2 = Counter(s2)
        
        ans = 0
        hs = set()
        
        for char in s2:
            if char not in hs:
                hs.add(char)
                x1 = m1[char]
                x2 = m2[char]
                x1 = min(x1, x2)
                ans += x1
        
        print(ans)

if __name__ == "__main__":
    main()
