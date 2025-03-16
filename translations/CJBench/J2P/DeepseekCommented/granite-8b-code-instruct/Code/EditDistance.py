

def minDistance(word1, word2):
    len1 = len(word1) # Get the length of the first word
    len2 = len(word2) # Get the length of the second word
    dp = [[0 for _ in range(len2 + 1)] for _ in range(len1 + 1)] # Create a 2D array to store distances
    # Initialize the first row and column of the array
    for i in range(len1 + 1):
        dp[i][0] = i # Initialize the distance for deleting characters
    for j in range(len2 + 1):
        dp[0][j] = j # Initialize the distance for inserting characters
    # Fill the rest of the array using dynamic programming
    for i in range(1, len1 + 1):
        c1 = word1[i - 1] # Get the i-th character of the first word
        for j in range(1, len2 + 1):
            c2 = word2[j - 1] # Get the j-th character of the second word
            if c1 == c2:
                dp[i][j] = dp[i - 1][j - 1] # No operation needed if characters are the same
            else:
                replace = dp[i - 1][j - 1] + 1 # Cost of replacing a character
                insert = dp[i][j - 1] + 1 # Cost of inserting a character
                delete = dp[i - 1][j] + 1 # Cost of deleting a character
                dp[i][j] = min(replace, min(insert, delete)) # Choose the minimum cost operation
    return dp[len1][len2] # Return the minimum edit distance

# Main method to read input words and calculate their minimum edit distance
if __name__ == "__main__":
    word1 = input() # Read the first word
    word2 = input() # Read the second word
    result = minDistance(word1, word2) # Calculate the minimum edit distance
    print("The minimum edit distance is:", result) # Print the result

