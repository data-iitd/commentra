

def min_distance(word1, word2):
    len1 = len(word1) # Length of first string
    len2 = len(word2) # Length of second string

    # 2D array to store the minimum edit distance between substrings
    dp = [[0 for _ in range(len2 + 1)] for _ in range(len1 + 1)]

    # Initialize first row and column with their respective indices
    for i in range(len1 + 1):
        dp[i][0] = i # i operations to delete all characters of word2
    for j in range(len2 + 1):
        dp[0][j] = j # j operations to delete all characters of word1

    # Fill in the rest of the dp array
    for i in range(1, len1 + 1):
        c1 = word1[i - 1] # Get character at current index of word1
        for j in range(1, len2 + 1):
            c2 = word2[j - 1] # Get character at current index of word2
            if c1 == c2:
                dp[i][j] = dp[i - 1][j - 1] # No operation needed if characters are same
            else:
                replace = dp[i - 1][j - 1] + 1 # Replace current character of word1 with current character of word2 and increment by 1
                insert = dp[i][j - 1] + 1 # Insert current character of word2 after current character of word1 and increment by 1
                delete = dp[i - 1][j] + 1 # Delete current character of word1 and increment by 1
                dp[i][j] = min(replace, min(insert, delete)) # Choose the minimum of three operations

    # Return the minimum edit distance between the two strings
    return dp[len1][len2]

# Main method to read input and print output
if __name__ == "__main__":
    word1 = input("Enter the first string: ") # Read the first string from the user
    word2 = input("Enter the second string: ") # Read the second string from the user
    result = min_distance(word1, word2) # Find the minimum edit distance between the two strings
    print("The minimum edit distance is:", result) # Print the minimum edit distance to the console

