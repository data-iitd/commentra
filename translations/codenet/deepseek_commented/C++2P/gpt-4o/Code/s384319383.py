def main():
    n = int(input())  # Read the number of characters
    cnt = [1] * 26  # Initialize a list to count occurrences of each letter, starting with 1 for each
    s = list(input().strip())  # Read the characters as a list

    for char in s:
        cnt[ord(char) - ord('a')] += 1  # Increment the count for the corresponding letter

    ans = cnt[0]  # Initialize the answer with the count of the first letter
    MOD = int(1e9 + 7)  # Define the modulo constant

    for i in range(1, 26):  # Loop through the counts of other letters
        ans *= cnt[i]  # Multiply the answer by the count of the current letter
        ans %= MOD  # Take the modulo to prevent overflow

    print(ans - 1)  # Output the result, subtracting 1 because we don't count the empty set

if __name__ == "__main__":
    main()

# <END-OF-CODE>
