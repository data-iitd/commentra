import sys
from collections import defaultdict

class Card:
    def __init__(self):
        self.left = 0

    def __lt__(self, other):
        return self.left < other.left

def main():
    # Read the first line of input and extract n and k
    n, k = map(int, sys.stdin.readline().split())
    
    # Create a list of Card objects to count occurrences of each letter
    cards = [Card() for _ in range(26)]
    
    # Read the string of cards and count the occurrences of each letter
    s = sys.stdin.readline().strip()
    for char in s:
        cards[ord(char) - ord('A')].left += 1
    
    ans = 0  # Variable to store the final answer
    
    # Perform k operations to maximize the score
    for _ in range(k):
        cards.sort()  # Sort the cards based on the count of letters
        
        # Determine the number of changes to make for the most frequent letter
        change = min(cards[25].left, k)  # cards[25] is the most frequent letter
        ans += change * change  # Update the answer with the square of changes
        
        # Decrease the count of the most frequent letter by the number of changes made
        cards[25].left -= change
        k -= change  # Decrease k by the number of changes made
        
        if k <= 0:
            break  # Exit if no more changes are allowed
    
    # Output the final result
    print(ans)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
