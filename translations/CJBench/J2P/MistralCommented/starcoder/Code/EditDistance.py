
# Final class to prevent instantiation
class Main:
    # Private constructor to prevent instantiation
    def __init__(self):
        pass

    # Method to find minimum edit distance between two strings
    def minDistance(self, word1, word2):
        len1 = len(word1) # Length of first string
        len2 = len(word2) # Length of second string

        # 2D array to store the minimum edit distance between substrings
        dp = [[0 for i in range(len2 + 1)] for j in range(len1 + 1)]

        # Initialize first row and column with their respective indices
        for i in range(len1 + 1):
            dp[i][0] = i # i operations to delete all characters of word2
        for j in range(len2 + 1):
            dp[0][j] = j # j operations to delete all characters of word1

        # Fill in the rest of the dp array
        for i in range(len1):
            c1 = word1[i] # Get character at current index of word1
            for j in range(len2):
                c2 = word2[j] # Get character at current index of word2
                if c1 == c2:
                    dp[i + 1][j + 1] = dp[i][j] # No operation needed if characters are same
                else:
                    replace = dp[i][j] + 1 # Replace current character of word1 with current character of word2 and increment by 1
                    insert = dp[i][j + 1] + 1 # Insert current character of word2 after current character of word1 and increment by 1
                    delete = dp[i + 1][j] + 1 # Delete current character of word1 and increment by 1
                    dp[i + 1][j + 1] = min(replace, min(insert, delete)) # Choose the minimum of three operations
        # Return the minimum edit distance between the two strings
        return dp[len1][len2]

    # Main method to read input and print output
    def main(self):
        word1 = input() # Read the first string from the user
        word2 = input() # Read the second string from the user
        result = self.minDistance(word1, word2) # Find the minimum edit distance between the two strings
        print("The minimum edit distance is: " + str(result)) # Print the minimum edit distance to the console

# 