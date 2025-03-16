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
    
    n, k = map(int, data[0].split())  # Reading the number of cards and the number of queries
    cards = [Card() for _ in range(26)]  # Creating a list of 26 Card objects

    s = data[1]  # Reading the sequence of cards
    for char in s:  # Iterating through each character in the sequence
        cards[ord(char) - ord('A')].left += 1  # Incrementing the left counter of the corresponding card

    ans = 0  # Initializing the answer variable to zero
    for i in range(k):  # Iterating through each query
        cards.sort()  # Sorting the cards list in ascending order of their left counters
        change = min(cards[25].left, k - i)  # Calculating the number of cards to be moved
        ans += change * change  # Adding the square of the number of cards moved to the answer
        cards[25].left -= change  # Decreasing the left counter of the highest card by the number of cards moved
        i += change - 1  # Skipping the next i-1 cards as they will have the same left counter

    print(ans)  # Writing the answer to the standard output

if __name__ == "__main__":
    main()

# <END-OF-CODE>
