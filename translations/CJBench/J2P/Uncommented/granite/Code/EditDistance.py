

def minDistance(word1, word2):
    len1 = len(word1)
    len2 = len(word2)
    dp = [[0 for _ in range(len2 + 1)] for _ in range(len1 + 1)]
    for i in range(len1 + 1):
        dp[i][0] = i
    for j in range(len2 + 1):
        dp[0][j] = j
    for i in range(1, len1 + 1):
        c1 = word1[i - 1]
        for j in range(1, len2 + 1):
            c2 = word2[j - 1]
            if c1 == c2:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                replace = dp[i - 1][j - 1] + 1
                insert = dp[i][j - 1] + 1
                delete = dp[i - 1][j] + 1
                dp[i][j] = min(replace, min(insert, delete))
    return dp[len1][len2]

word1 = input()
word2 = input()
result = minDistance(word1, word2)
print("The minimum edit distance is:", result)

