
# <START-OF-CODE>
import sys

def main():
    f = open(sys.argv[1], 'r')
    out = open(sys.argv[2], 'w')
    n, k = map(int, f.readline().split())
    cards = [0] * 26
    s = f.readline()
    for t in range(n):
        cards[ord(s[t]) - ord('A')] += 1
    ans = 0
    for i in range(k):
        cards.sort()
        change = min(cards[25], k - i)
        ans += change * change
        cards[25] -= change
        i += change - 1
    out.write(str(ans) + '\n')
    out.close()

if __name__ == '__main__':
    main()
# 