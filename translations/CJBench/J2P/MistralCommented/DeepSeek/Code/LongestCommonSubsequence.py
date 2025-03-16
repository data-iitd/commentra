def get_lcs(str1, str2):
    if str1 is None or str2 is None:
        return None
    if len(str1) == 0 or len(str2) == 0:
        return ""
    
    arr1 = list(str1)
    arr2 = list(str2)
    
    lcs_matrix = [[0] * (len(arr2) + 1) for _ in range(len(arr1) + 1)]
    
    for i in range(len(arr1) + 1):
        lcs_matrix[i][0] = 0
    
    for j in range(1, len(arr2) + 1):
        lcs_matrix[0][j] = 0
    
    for i in range(1, len(arr1) + 1):
        for j in range(1, len(arr2) + 1):
            if arr1[i - 1] == arr2[j - 1]:
                lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1
            else:
                lcs_matrix[i][j] = max(lcs_matrix[i - 1][j], lcs_matrix[i][j - 1])
    
    return lcs_string(str1, str2, lcs_matrix)


def lcs_string(str1, str2, lcs_matrix):
    lcs = []
    i = len(str1)
    j = len(str2)
    
    while i > 0 and j > 0:
        if str1[i - 1] == str2[j - 1]:
            lcs.append(str1[i - 1])
            i -= 1
            j -= 1
        elif lcs_matrix[i - 1][j] > lcs_matrix[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    return ''.join(reversed(lcs))


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    str1 = data[0]
    str2 = data[1]
    
    lcs = get_lcs(str1, str2)
    print("The Longest Common Subsequence is: " + lcs)


if __name__ == "__main__":
    main()
