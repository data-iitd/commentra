import sys
from collections import defaultdict

class Card:
    def __init__(self):
        self.left = 0

    def __lt__(self, other):
        return self.left < other.left

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    n, k = map(int, data[0].split())
    cards = [Card() for _ in range(26)]
    
    s = data[1]
    for char in s:
        cards[ord(char) - ord('A')].left += 1
    
    ans = 0
    for i in range(k):
        cards.sort()
        change = min(cards[25].left, k - i)
        ans += change * change
        cards[25].left -= change
        i += change - 1
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
