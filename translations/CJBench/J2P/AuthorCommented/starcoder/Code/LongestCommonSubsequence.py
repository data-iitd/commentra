
import sys

class Main:

    def __init__(self):
        pass

    def getLCS(self, str1, str2):
        if str1 == None or str2 == None:
            return None
        # If either string is null, return null as LCS can't be computed.
        if len(str1) == 0 or len(str2) == 0:
            return ""

        # Convert the strings into arrays of characters
        arr1 = str1.split("")
        arr2 = str2.split("")

        # lcsMatrix[i][j] = LCS(first i characters of str1, first j characters of str2)
        lcsMatrix = [[0 for x in range(len(arr2) + 1)] for x in range(len(arr1) + 1)]

        # Base Case: Fill the LCS matrix 0th row & 0th column with 0s
        # as LCS of any string with an empty string is 0.
        for i in range(len(arr1) + 1):
            lcsMatrix[i][0] = 0
        for j in range(len(arr2) + 1):
            lcsMatrix[0][j] = 0

        # Build the LCS matrix by comparing characters of str1 & str2
        for i in range(1, len(arr1) + 1):
            for j in range(1, len(arr2) + 1):
                # If characters match, the LCS increases by 1
                if arr1[i - 1] == arr2[j - 1]:
                    lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1
                else:
                    # Otherwise, take the maximum of the left or above values
                    lcsMatrix[i][j] = max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1])

        # Call helper function to reconstruct the LCS from the matrix
        return self.lcsString(str1, str2, lcsMatrix)

    def lcsString(self, str1, str2, lcsMatrix):
        lcs = ""
        i = len(str1)
        j = len(str2)

        # Trace back through the LCS matrix to reconstruct the LCS
        while i > 0 and j > 0:
            # If characters match, add to the LCS and move diagonally in the matrix
            if str1[i - 1] == str2[j - 1]:
                lcs = str1[i - 1] + lcs
                i -= 1
                j -= 1
            else:
                # If the value above is larger, move up
                if lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]:
                    i -= 1
                # If the value to the left is larger, move left
                else:
                    j -= 1

        return lcs

    def main(self):
        str1 = sys.stdin.readline().strip()
        str2 = sys.stdin.readline().strip()

        lcs = self.getLCS(str1, str2)
        print("The Longest Common Subsequence is: " + lcs)

# 