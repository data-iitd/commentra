

import sys
from array import array  # Importing required Python modules for input and output
from itertools import *  # Importing required Python modules for string tokenization

def main():
    n, k = map(int, input().split())  # Reading the number of cards and queries from the standard input
    s = input()  # Reading the sequence of cards from the standard input
    cards = [0] * 26  # Creating an array of size 26 to store the cards
    for c in s:  # Iterating through each character in the sequence
        cards[ord(c) - ord('A')] += 1  # Incrementing the left counter of the corresponding card
    ans = 0  # Initializing the answer variable to zero
    for _ in range(k):  # Iterating through each query
        cards.sort(reverse=True)  # Sorting the cards array in descending order of their left counters
        change = min(cards[0], k - _)  # Calculating the number of cards to be moved
        ans += change * change  # Adding the square of the number of cards moved to the answer
        cards[0] -= change  # Decreasing the left counter of the highest card by the number of cards moved
    print(ans)  # Writing the answer to the standard output

if __name__ == "__main__":
    sys.exit(main())

