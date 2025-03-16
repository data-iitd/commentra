

def minDistance(word1, word2):
    len1 = len(word1)
    len2 = len(word2)
    # len1+1, len2+1, because finally return dp[len1][len2]
    dp = [[0 for x in range(len2+1)] for x in range(len1+1)]

    # If second string is empty, the only option is to
    # insert all characters of first string into second
    for i in range(len1+1):
        dp[i][0] = i

    # If first string is empty, the only option is to
    # insert all characters of second string into first
    for j in range(len2+1):
        dp[0][j] = j

    # iterate though, and check last char
    for i in range(1, len1+1):
        c1 = word1[i-1]
        for j in range(1, len2+1):
            c2 = word2[j-1]
            # if last two chars equal
            if c1 == c2:
                # update dp value for +1 length
                dp[i][j] = dp[i-1][j-1]
            else:
                # if two characters are different,
                # then take the minimum of the various operations(i.e insertion,removal,substitution)
                replace = dp[i-1][j-1] + 1
                insert = dp[i][j-1] + 1
                delete = dp[i-1][j] + 1
                dp[i][j] = min(replace, insert, delete)

    # return the final answer, after traversing through both the strings
    return dp[len1][len2]

if __name__ == '__main__':
    import sys

    word1 = input().strip()
    word2 = input().strip()

    result = minDistance(word1, word2)
    print("The minimum edit distance is: " + str(result))

