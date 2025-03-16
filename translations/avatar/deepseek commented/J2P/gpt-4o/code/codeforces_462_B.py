import sys
from collections import defaultdict

class C462B:
    def __init__(self):
        self.left = 0

    def __lt__(self, other):
        return self.left < other.left

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    n, k = map(int, data[0].split())
    cards = [C462B() for _ in range(26)]
    
    s = data[1]
    for char in s:
        cards[ord(char) - ord('A')].left += 1
    
    ans = 0
    for i in range(k):
        cards.sort()  # Sort the cards based on the left property
        change = min(cards[25].left, k - i)  # Get the minimum between the largest left value and remaining k - i
        ans += change * change  # Add the square of the calculated value to ans
        cards[25].left -= change  # Decrement the left property of the largest element
        i += change - 1  # Adjust the loop counter
    
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
