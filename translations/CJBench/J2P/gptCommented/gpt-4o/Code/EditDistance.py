class Main:
    @staticmethod
    def min_distance(word1, word2):
        # Get the lengths of both words
        len1 = len(word1)
        len2 = len(word2)
        
        # Create a 2D array to store the edit distances
        dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

        # Initialize the first column of the dp array
        for i in range(len1 + 1):
            dp[i][0] = i

        # Initialize the first row of the dp array
        for j in range(len2 + 1):
            dp[0][j] = j

        # Fill the dp array using the edit distance dynamic programming approach
        for i in range(len1):
            c1 = word1[i]
            for j in range(len2):
                c2 = word2[j]
                
                # If the characters match, no new edit is needed
                if c1 == c2:
                    dp[i + 1][j + 1] = dp[i][j]
                else:
                    # Calculate costs for replace, insert, and delete operations
                    replace = dp[i][j] + 1  # Cost of replacing a character
                    insert = dp[i][j + 1] + 1  # Cost of inserting a character
                    delete = dp[i + 1][j] + 1  # Cost of deleting a character
                    
                    # Take the minimum of the three operations
                    dp[i + 1][j + 1] = min(replace, insert, delete)
        
        # Return the minimum edit distance found in the last cell of the dp array
        return dp[len1][len2]

# Main execution
if __name__ == "__main__":
    # Read the first word from the user
    word1 = input()
    
    # Read the second word from the user
    word2 = input()
    
    # Calculate the minimum edit distance between the two words
    result = Main.min_distance(word1, word2)
    
    # Output the result to the console
    print("The minimum edit distance is:", result)

# <END-OF-CODE>
