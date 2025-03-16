def min_distance(word1, word2):
    len1 = len(word1)  # Get the length of the first word
    len2 = len(word2)  # Get the length of the second word
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]  # Create a 2D array to store distances
    # Initialize the first row and column of the array
    for i in range(len1 + 1):
        dp[i][0] = i  # Initialize the distance for deleting characters
    for j in range(len2 + 1):
        dp[0][j] = j  # Initialize the distance for inserting characters
    # Fill the rest of the array using dynamic programming
    for i in range(len1):
        c1 = word1[i]  # Get the i-th character of the first word
        for j in range(len2):
            c2 = word2[j]  # Get the j-th character of the second word
            if c1 == c2:
                dp[i + 1][j + 1] = dp[i][j]  # No operation needed if characters are the same
            else:
                replace = dp[i][j] + 1  # Cost of replacing a character
                insert = dp[i][j + 1] + 1  # Cost of inserting a character
                delete = dp[i + 1][j] + 1  # Cost of deleting a character
                dp[i + 1][j + 1] = min(replace, insert, delete)  # Choose the minimum cost operation
    return dp[len1][len2]  # Return the minimum edit distance


# Main method to read input words and calculate their minimum edit distance
def main():
    import sys
    # Read the first word
    word1 = sys.stdin.readline().strip()
    # Read the second word
    word2 = sys.stdin.readline().strip()
    result = min_distance(word1, word2)  # Calculate the minimum edit distance
    print("The minimum edit distance is:", result)  # Print the result


main()
