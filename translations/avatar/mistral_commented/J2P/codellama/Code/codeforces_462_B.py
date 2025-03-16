
import sys
import math

n, k = map(int, sys.stdin.readline().split())
cards = [0] * 26

for i in range(n):
    cards[ord(sys.stdin.readline()[i]) - ord('A')] += 1

ans = 0
for i in range(k):
    cards.sort(reverse=True)
    change = min(cards[25], k - i)
    ans += change * change
    cards[25] -= change
    i += change - 1

print(ans)

