
import sys

def minimalPartitions(word):
    len = len(word)
    minCuts = [0] * len
    isPalindrome = [[False] * len for i in range(len)]
    for i in range(len):
        isPalindrome[i][i] = True
    for subLen in range(2, len + 1):
        for i in range(len - subLen + 1):
            j = i + subLen - 1
            if subLen == 2:
                isPalindrome[i][j] = (word[i] == word[j])
            else:
                isPalindrome[i][j] = (word[i] == word[j]) and isPalindrome[i + 1][j - 1]
    for i in range(len):
        if isPalindrome[0][i]:
            minCuts[i] = 0
        else:
            minCuts[i] = sys.maxint
            for j in range(0, i):
                if isPalindrome[j + 1][i] and 1 + minCuts[j] < minCuts[i]:
                    minCuts[i] = 1 + minCuts[j]
    return minCuts[len - 1]

if __name__ == "__main__":
    inputString = raw_input()
    result = minimalPartitions(inputString)
    print "Minimum number of partitions required: " + str(result)

