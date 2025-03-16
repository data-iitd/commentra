
import sys

class Main:
    def __init__(self):
        pass

    def minimalPartitions(self, word):
        len = len(word)
        # We Make two arrays to create a bottom-up solution.
        # minCuts[i] = Minimum number of cuts needed for palindrome partitioning of substring
        # word[0..i] isPalindrome[i][j] = true if substring str[i..j] is palindrome Base Condition:
        # C[i] is 0 if P[0][i]= true
        minCuts = [0] * len
        isPalindrome = [[False] * len for i in range(len)]

        # Every substring of length 1 is a palindrome
        for i in range(len):
            isPalindrome[i][i] = True

        # subLen is substring length. Build the solution in bottom up manner by considering all
        # substrings of length starting from 2 to n.
        for subLen in range(2, len + 1):
            # For substring of length subLen, set different possible starting indexes
            for i in range(0, len - subLen + 1):
                j = i + subLen - 1 # Ending index
                # If subLen is 2, then we just need to
                # compare two characters. Else need to
                # check two corner characters and value
                # of P[i+1][j-1]
                if subLen == 2:
                    isPalindrome[i][j] = (word[i] == word[j])
                else:
                    isPalindrome[i][j] = (word[i] == word[j]) and isPalindrome[i + 1][j - 1]

        # We find the minimum for each index
        for i in range(len):
            if isPalindrome[0][i]:
                minCuts[i] = 0
            else:
                minCuts[i] = sys.maxsize
                for j in range(0, i):
                    if isPalindrome[j + 1][i] and 1 + minCuts[j] < minCuts[i]:
                        minCuts[i] = 1 + minCuts[j]

        # Return the min cut value for complete
        # string. i.e., str[0..n-1]
        return minCuts[len - 1]

if __name__ == '__main__':
    inputString = input()
    main = Main()
    result = main.minimalPartitions(inputString)
    print("Minimum number of partitions required: " + str(result))

