import sys
from collections import Counter

# Read the input from stdin
n, k = map(int, sys.stdin.readline().split())
cards = Counter(sys.stdin.readline().strip())

# Initialize the answer variable
ans = 0

# Perform k operations to maximize the score
for _ in range(k):
    # Find the most common card and the number of changes to make
    most_common_card = cards.most_common(1)[0]
    change = min(most_common_card[1], k)
    
    # Update the answer with the square of changes
    ans += change * change
    
    # Decrease the count of the most frequent card by the number of changes made
    cards[most_common_card[0]] -= change
    k -= change

# Output the final result
print(ans)
