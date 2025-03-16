import sys

class Card:
    def __init__(self):
        self.left = 0

    def __lt__(self, other):
        return self.left < other.left

def main():
    # Read input from stdin
    input_line = sys.stdin.readline().strip()
    n, k = map(int, input_line.split())
    
    # Initialize cards
    cards = [Card() for _ in range(26)]
    
    # Read the string
    s = sys.stdin.readline().strip()
    
    # Count the occurrences of each character
    for t in range(n):
        cards[ord(s[t]) - ord('A')].left += 1
    
    # Calculate the answer
    ans = 0
    for i in range(k):
        # Sort the cards
        cards.sort()
        # Calculate the change
        change = min(cards[-1].left, k - i)
        ans += change * change
        cards[-1].left -= change
        i += change - 1
    
    # Print the answer
    print(ans)

if __name__ == "__main__":
    main()
