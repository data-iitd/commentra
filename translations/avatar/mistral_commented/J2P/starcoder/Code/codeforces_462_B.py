
import sys

# Reading input from standard input
f = sys.stdin

# Reading the number of cards
n = int(f.readline())

# Reading the number of queries
k = int(f.readline())

# Creating an array of size 26 to store the cards
cards = [0] * 26

# Initializing the cards array with default values
for i in range(26):
    cards[i] = c462b()

# Reading the sequence of cards
s = f.readline()

# Iterating through each character in the sequence
for t in range(n):
    cards[ord(s[t]) - ord('A')].left += 1

# Initializing the answer variable to zero
ans = 0

# Iterating through each query
for i in range(k):
    # Sorting the cards array in descending order of their left counters
    cards.sort(reverse=True)

    # Calculating the number of cards to be moved
    change = min(cards[25].left, k - i)

    # Adding the square of the number of cards moved to the answer
    ans += change * change

    # Decreasing the left counter of the highest card by the number of cards moved
    cards[25].left -= change

    # Skipping the next i-1 cards as they will have the same left counter
    i += change - 1

# Writing the answer to the standard output
print(ans)

# Closing the output stream
f.close()

# Defining an inner class to represent a card
class c462b:
    def __init__(self):
        self.left = 0

    def __lt__(self, other):
        return self.left < other.left

