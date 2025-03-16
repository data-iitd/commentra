import sys

# Class to represent each card and implement Comparable for sorting
class c462b:
    def __init__(self):
        self.left = 0 # Count of letters left
    
    def __lt__(self, other):
        return self.left < other.left # Compare based on the count of letters

# Main function
def main():
    # Read the first line of input and tokenize it to extract n and k
    n, k = map(int, sys.stdin.readline().split())
    
    # Create an array of c462b objects to count occurrences of each letter
    cards = [c462b() for i in range(26)] 
    
    # Read the string of cards and count the occurrences of each letter
    s = sys.stdin.readline()
    for t in range(n):
        cards[ord(s[t]) - ord('A')].left += 1 # Increment the count for the corresponding letter
    
    ans = 0 # Variable to store the final answer
    
    # Perform k operations to maximize the score
    for i in range(k):
        cards.sort() # Sort the cards based on the count of letters
        
        # Determine the number of changes to make for the most frequent letter
        change = min(cards[25].left, k - i)
        ans += change * change # Update the answer with the square of changes
        
        # Decrease the count of the most frequent letter by the number of changes made
        cards[25].left -= change
        i += change - 1 # Adjust the loop counter based on changes made
    
    # Output the final result
    print(ans)

if __name__ == "__main__":
    main()

# 