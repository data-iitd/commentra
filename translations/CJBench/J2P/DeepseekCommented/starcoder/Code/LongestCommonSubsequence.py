import sys

# Method to find the Longest Common Subsequence (LCS) of two strings
def getLCS(str1, str2):
    # Check if either string is null or empty
    if str1 == None or str2 == None:
        return None
    if len(str1) == 0 or len(str2) == 0:
        return ""

    # Split the strings into arrays of characters
    arr1 = str1.split("")
    arr2 = str2.split("")

    # Initialize a matrix to store LCS lengths
    lcsMatrix = [[0 for x in range(len(arr2) + 1)] for y in range(len(arr1) + 1)]

    # Populate the matrix
    for i in range(len(arr1) + 1):
        lcsMatrix[i][0] = 0
    for j in range(len(arr2) + 1):
        lcsMatrix[0][j] = 0
    for i in range(1, len(arr1) + 1):
        for j in range(1, len(arr2) + 1):
            if arr1[i - 1] == arr2[j - 1]:
                lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1
            else:
                lcsMatrix[i][j] = max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1])

    # Reconstruct the LCS string
    return lcsString(str1, str2, lcsMatrix)

# Helper method to build the LCS string from the matrix
def lcsString(str1, str2, lcsMatrix):
    lcs = ""
    i = len(str1)
    j = len(str2)
    while i > 0 and j > 0:
        if str1[i - 1] == str2[j - 1]:
            lcs = str1[i - 1] + lcs
            i -= 1
            j -= 1
        elif lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]:
            i -= 1
        else:
            j -= 1
    return lcs

# Main method to read input strings and print the LCS
def main():
    str1 = sys.stdin.readline().strip()
    str2 = sys.stdin.readline().strip()
    lcs = getLCS(str1, str2)
    print("The Longest Common Subsequence is: " + lcs)

if __name__ == "__main__":
    main()

