class Main:
    # Method to compute the Longest Common Subsequence (LCS) of two strings
    @staticmethod
    def get_lcs(str1, str2):
        # Check for null input strings
        if str1 is None or str2 is None:
            return None
        # Return an empty string if either string is empty
        if len(str1) == 0 or len(str2) == 0:
            return ""

        # Create a matrix to store lengths of longest common subsequence
        lcs_matrix = [[0] * (len(str2) + 1) for _ in range(len(str1) + 1)]

        # Fill the LCS matrix using dynamic programming
        for i in range(1, len(str1) + 1):
            for j in range(1, len(str2) + 1):
                # If characters match, increment the value from the diagonal cell
                if str1[i - 1] == str2[j - 1]:
                    lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1
                else:
                    # Otherwise, take the maximum value from the left or above cell
                    lcs_matrix[i][j] = max(lcs_matrix[i - 1][j], lcs_matrix[i][j - 1])

        # Retrieve the longest common subsequence from the matrix
        return Main.lcs_string(str1, str2, lcs_matrix)

    # Method to construct the LCS string from the LCS matrix
    @staticmethod
    def lcs_string(str1, str2, lcs_matrix):
        lcs = []
        i, j = len(str1), len(str2)

        # Backtrack through the matrix to find the LCS characters
        while i > 0 and j > 0:
            # If characters match, add to the LCS and move diagonally
            if str1[i - 1] == str2[j - 1]:
                lcs.append(str1[i - 1])
                i -= 1
                j -= 1
            elif lcs_matrix[i - 1][j] > lcs_matrix[i][j - 1]:
                # Move up if the value above is greater
                i -= 1
            else:
                # Move left if the value to the left is greater
                j -= 1

        # Reverse the LCS string since we constructed it backwards
        return ''.join(reversed(lcs))

# Main execution
if __name__ == "__main__":
    # Read two strings from the user
    str1 = input()
    str2 = input()
    
    # Compute the LCS of the two strings
    lcs = Main.get_lcs(str1, str2)
    
    # Output the result
    print("The Longest Common Subsequence is:", lcs)

# <END-OF-CODE>
