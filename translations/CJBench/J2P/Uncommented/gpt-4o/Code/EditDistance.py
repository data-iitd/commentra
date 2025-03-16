def min_distance(word1, word2):
    len1 = len(word1)
    len2 = len(word2)
    dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
    
    for i in range(len1 + 1):
        dp[i][0] = i
    for j in range(len2 + 1):
        dp[0][j] = j
    
    for i in range(len1):
        c1 = word1[i]
        for j in range(len2):
            c2 = word2[j]
            if c1 == c2:
                dp[i + 1][j + 1] = dp[i][j]
            else:
                replace = dp[i][j] + 1
                insert = dp[i][j + 1] + 1
                delete = dp[i + 1][j] + 1
                dp[i + 1][j + 1] = min(replace, insert, delete)
    
    return dp[len1][len2]

if __name__ == "__main__":
    word1 = input()
    word2 = input()
    result = min_distance(word1, word2)
    print("The minimum edit distance is:", result)

# <END-OF-CODE>
