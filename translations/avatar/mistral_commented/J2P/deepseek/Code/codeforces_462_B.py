import sys
from io import StringIO

class Card:
    def __init__(self):
        self.left = 0

    def __lt__(self, other):
        return self.left < other.left

def main():
    # Reading input from standard input
    input_text = sys.stdin.read()
    input_lines = input_text.strip().split('\n')
    
    # Tokenizing the first line of input
    first_line_tokens = input_lines[0].split()
    n = int(first_line_tokens[0])
    k = int(first_line_tokens[1])
    
    # Creating an array of size 26 to store the cards
    cards = [Card() for _ in range(26)]
    
    # Reading the sequence of cards
    sequence = input_lines[1]
    
    # Iterating through each character in the sequence
    for t in range(n):
        cards[ord(sequence[t]) - ord('A')].left += 1
    
    # Initializing the answer variable to zero
    ans = 0
    
    # Iterating through each query
    for i in range(k):
        # Sorting the cards array in descending order of their left counters
        cards.sort(reverse=True)
        
        # Calculating the number of cards to be moved
        change = min(cards[0].left, k - i)
        
        # Adding the square of the number of cards moved to the answer
        ans += change * change
        
        # Decreasing the left counter of the highest card by the number of cards moved
        cards[0].left -= change
        
        # Skipping the next i cards as they will have the same left counter
        i += change - 1
    
    # Writing the answer to the standard output
    print(ans)

if __name__ == "__main__":
    main()

