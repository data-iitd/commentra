import sys
import math

def main():
    n, k = map(int, sys.stdin.readline().split())
    cards = [0] * 26
    for i in range(26):
        cards[i] = [0, 0]
    s = sys.stdin.readline()
    for t in range(n):
        cards[ord(s[t]) - ord('A')][0] += 1
    ans = 0
    for i in range(k):
        cards.sort(key=lambda x: x[0])
        change = min(cards[25][0], k - i)
        ans += change * change
        cards[25][0] -= change
        i += change - 1
    print(ans)

if __name__ == '__main__':
    main()

