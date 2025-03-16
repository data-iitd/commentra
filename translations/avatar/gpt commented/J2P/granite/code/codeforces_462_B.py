
import sys
from collections import Counter

def main():
    # Initialize variables to read input from standard input
    n, k = map(int, input().split()) # Number of cards and maximum number of changes allowed
    cards = Counter() # Create a dictionary to count occurrences of each letter
    
    # Read the string of cards and count the occurrences of each letter
    s = input() 
    for t in range(n): 
        cards[s[t]] += 1 # Increment the count for the corresponding letter
    
    ans = 0 # Variable to store the final answer
    
    # Perform k operations to maximize the score
    for i in range(k): 
        most_frequent = max(cards, key=cards.get) # Find the most frequent letter
        change = min(cards[most_frequent], k - i) # Determine the number of changes to make for the most frequent letter
        ans += change * change # Update the answer with the square of changes
        cards[most_frequent] -= change # Decrease the count of the most frequent letter by the number of changes made
        i += change - 1 # Adjust the loop counter based on changes made
    
    # Output the final result
    print(ans) 

if __name__ == "__main__":
    main()

