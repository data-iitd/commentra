import sys
import math

class c462b:
    def __init__(self):
        self.left = 0

def main():
    f = sys.stdin
    out = sys.stdout
    n, k = map(int, f.readline().split())
    cards = [c462b() for i in range(26)]
    s = f.readline()
    for t in range(n):
        cards[ord(s[t]) - ord('A')].left += 1
    ans = 0
    for i in range(k):
        cards.sort()
        change = min(cards[25].left, k - i)
        ans += change * change
        cards[25].left -= change
        i += change - 1
    out.write(str(ans) + '\n')

if __name__ == '__main__':
    main()

