class EditDistance:
    @staticmethod
    def min_distance(word1: str, word2: str) -> int:
        len1 = len(word1)
        len2 = len(word2)
        # len1+1, len2+1, because finally return dp[len1][len2]
        dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]

        # If second string is empty, the only option is to insert all characters of first string into second
        for i in range(len1 + 1):
            dp[i][0] = i

        # If first string is empty, the only option is to insert all characters of second string into first
        for j in range(len2 + 1):
            dp[0][j] = j

        # iterate through, and check last char
        for i in range(len1):
            c1 = word1[i]
            for j in range(len2):
                c2 = word2[j]
                # if last two chars equal
                if c1 == c2:
                    # update dp value for +1 length
                    dp[i + 1][j + 1] = dp[i][j]
                else:
                    # if two characters are different, then take the minimum of the various operations
                    replace = dp[i][j] + 1
                    insert = dp[i][j + 1] + 1
                    delete = dp[i + 1][j] + 1
                    dp[i + 1][j + 1] = min(replace, insert, delete)

        # return the final answer, after traversing through both the strings
        return dp[len1][len2]

if __name__ == "__main__":
    word1 = input()
    word2 = input()

    result = EditDistance.min_distance(word1, word2)
    print("The minimum edit distance is:", result)

# <END-OF-CODE>
