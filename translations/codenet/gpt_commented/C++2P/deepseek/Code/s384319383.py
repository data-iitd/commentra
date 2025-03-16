# Macro definitions for convenience
def REP(i, n):
    return range(n)

def ALL(v):
    return v

INF = 1e9
MOD = 10**9 + 7

# Type alias for long long
from typing import List

# Main function
def main():
    n = int(input())  # Variable to store the number of characters

    # Initialize a list to count occurrences of each character (a-z)
    cnt = [1] * 26  # Start with 1 to account for the multiplication later
    s = list(input())  # List to store the input characters

    # Count their occurrences
    for i in REP(n):
        cnt[ord(s[i]) - ord('a')] += 1  # Increment the count for the corresponding character

    ans = cnt[0]  # Initialize answer with the count of 'a'
    
    # Calculate the product of counts for all characters from 'b' to 'z'
    for i in range(1, 26):
        ans *= cnt[i]  # Multiply the current answer by the count of the character
        ans %= MOD  # Take modulo to prevent overflow

    # Output the final result, subtracting 1 to exclude the empty product case
    print(ans - 1)

# Call the main function
if __name__ == "__main__":
    main()
