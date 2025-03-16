
import sys

def getLCS(str1, str2):
    if str1 == None or str2 == None:
        # Return null if either string is null
        return None
    if len(str1) == 0 or len(str2) == 0:
        # Return empty string if either string is empty
        return ""
    
    arr1 = str1.split("")
    arr2 = str2.split("")
    
    # Initialize a 2D matrix to store the lengths of the longest common subsequences of substrings
    lcsMatrix = [[0 for i in range(len(arr2) + 1)] for j in range(len(arr1) + 1)]
    
    for i in range(len(arr1) + 1):
        lcsMatrix[i][0] = 0
        # Initialize the first column of the matrix with zeros
    for j in range(len(arr2) + 1):
        lcsMatrix[0][j] = 0
        # Initialize the first row of the matrix with zeros
    for i in range(1, len(arr1) + 1):
        for j in range(1, len(arr2) + 1):
            if arr1[i - 1] == arr2[j - 1]:
                # If the characters at the current positions are the same,
                # add 1 to the length of the longest common subsequence of the substrings
                lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1
            else:
                # If the characters are different, take the maximum length of the longest common subsequences of the substrings that don't include the current characters
                lcsMatrix[i][j] = max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1])
    # Recursively build the longest common subsequence string from the matrix
    return lcsString(str1, str2, lcsMatrix)

def lcsString(str1, str2, lcsMatrix):
    lcs = ""
    i = len(str1)
    j = len(str2)
    
    # While there are still characters to process in both strings
    while i > 0 and j > 0:
        if str1[i - 1] == str2[j - 1]:
            # If the characters are the same, add them to the result string and move to the next character in both strings
            lcs = str1[i - 1] + lcs
            i -= 1
            j -= 1
        elif lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]:
            # If the length of the longest common subsequence of the substring that doesn't include the current character from str1 is greater than the length of the longest common subsequence of the substring that doesn't include the current character from str2,
            # move to the next character in str1
            i -= 1
        else:
            # Otherwise, move to the next character in str2
            j -= 1
    # Reverse the result string and return it
    return lcs

if __name__ == "__main__":
    str1 = sys.stdin.readline().strip()
    str2 = sys.stdin.readline().strip()
    
    # Call the getLCS method to find the longest common subsequence and print the result
    lcs = getLCS(str1, str2)
    print("The Longest Common Subsequence is: " + lcs)

