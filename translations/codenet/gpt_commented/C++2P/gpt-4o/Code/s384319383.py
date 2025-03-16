# Import necessary libraries
from collections import Counter

# Define constants
INF = 1e9  # Definition of infinity
MOD = 1e9 + 7  # Definition of modulus for large number calculations

# Main function
def main():
    n = int(input())  # Input the number of characters

    # Read characters and count their occurrences
    s = input().strip()  # Read the input characters as a string
    cnt = [1] * 26  # Initialize a list to count occurrences of each character (a-z), starting with 1

    # Count occurrences of each character
    for char in s:
        cnt[ord(char) - ord('a')] += 1  # Increment the count for the corresponding character

    ans = cnt[0]  # Initialize answer with the count of 'a'

    # Calculate the product of counts for all characters from 'b' to 'z'
    for i in range(1, 26):
        ans *= cnt[i]  # Multiply the current answer by the count of the character
        ans %= int(MOD)  # Take modulo to prevent overflow

    # Output the final result, subtracting 1 to exclude the empty product case
    print(ans - 1)

# Call the main function
if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
