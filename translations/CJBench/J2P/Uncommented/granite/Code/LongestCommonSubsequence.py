

def getLCS(str1, str2):
    if str1 is None or str2 is None:
        return None
    if len(str1) == 0 or len(str2) == 0:
        return ""
    arr1 = list(str1)
    arr2 = list(str2)
    lcsMatrix = [[0 for x in range(len(arr2) + 1)] for x in range(len(arr1) + 1)]
    for i in range(len(arr1) + 1):
        lcsMatrix[i][0] = 0
    for j in range(1, len(arr2) + 1):
        lcsMatrix[0][j] = 0
    for i in range(1, len(arr1) + 1):
        for j in range(1, len(arr2) + 1):
            if arr1[i - 1] == arr2[j - 1]:
                lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1
            else:
                lcsMatrix[i][j] = max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1])
    return lcsString(str1, str2, lcsMatrix)

def lcsString(str1, str2, lcsMatrix):
    lcs = ""
    i = len(str1)
    j = len(str2)
    while i > 0 and j > 0:
        if str1[i - 1] == str2[j - 1]:
            lcs += str1[i - 1]
            i -= 1
            j -= 1
        elif lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]:
            i -= 1
        else:
            j -= 1
    return lcs[::-1]

if __name__ == "__main__":
    str1 = input()
    str2 = input()
    lcs = getLCS(str1, str2)
    print("The Longest Common Subsequence is: " + lcs)

