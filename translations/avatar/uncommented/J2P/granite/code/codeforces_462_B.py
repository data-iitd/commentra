
import sys
import math

def main():
    n, k = map(int, input().split())
    cards = [0] * 26
    s = input()
    for c in s:
        cards[ord(c) - ord('A')] += 1
    ans = 0
    for i in range(k):
        cards.sort()
        change = min(cards[25], k - i)
        ans += change * change
        cards[25] -= change
        i += change - 1
    print(ans)

if __name__ == "__main__":
    main()

