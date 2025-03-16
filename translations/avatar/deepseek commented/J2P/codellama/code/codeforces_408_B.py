
import sys

def isValid(s1, s2):
    n1 = len(s1)
    n2 = len(s2)
    map = {}

    # Populate the map with characters from s1
    for c in s1:
        map[c] = True

    # Check if all characters of s1 are present in s2
    for c in s2:
        if not map.get(c):
            return False

    return True

def main():
    s1 = sys.stdin.readline().strip()
    s2 = sys.stdin.readline().strip()

    # Check if the strings are valid using the isValid method
    if isValid(s1, s2) == False:
        print(-1)
    else:
        m1 = {}
        m2 = {}

        # Populate the HashMap with the frequency of each character in s1
        for c in s1:
            if m1.get(c):
                m1[c] += 1
            else:
                m1[c] = 1

        # Populate the HashMap with the frequency of each character in s2
        for c in s2:
            if m2.get(c):
                m2[c] += 1
            else:
                m2[c] = 1

        ans = 0
        hs = set()

        # Iterate over the characters of s2
        for c in s2:
            if c not in hs:
                hs.add(c)
                x1 = m1.get(c)
                x2 = m2.get(c)
                x1 = min(x1, x2)
                ans += x1

        print(ans)

if __name__ == "__main__":
    main()

