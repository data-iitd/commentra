
import sys

def get_lcs(str1, str2):
    if str1 is None or str2 is None:
        # Return None if either string is None
        return None
    if len(str1) == 0 or len(str2) == 0:
        # Return an empty string if either string is empty
        return ""
    
    arr1 = list(str1)
    arr2 = list(str2)
    
    # Initialize a 2D matrix to store the lengths of the longest common subsequences of substrings
    lcs_matrix = [[0 for _ in range(len(arr2) + 1)] for _ in range(len(arr1) + 1)]
    
    for i in range(len(arr1) + 1):
        lcs_matrix[i][0] = 0
        # Initialize the first column of the matrix with zeros
    
    for j in range(1, len(arr2) + 1):
        lcs_matrix[0][j] = 0
        # Initialize the first row of the matrix with zeros
    
    for i in range(1, len(arr1) + 1):
        for j in range(1, len(arr2) + 1):
            if arr1[i - 1] == arr2[j - 1]:
                # If the characters at the current positions are the same,
                # add 1 to the length of the longest common subsequence of the substrings
                lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1
            else:
                # If the characters are different, take the maximum length of the longest common subsequences of the substrings that don't include the current characters
                lcs_matrix[i][j] = max(lcs_matrix[i - 1][j], lcs_matrix[i][j - 1])
    
    # Recursively build the longest common subsequence string from the matrix
    return lcs_string(str1, str2, lcs_matrix)

def lcs_string(str1, str2, lcs_matrix):
    lcs = ""
    i = len(str1)
    j = len(str2)
    
    # While there are still characters to process in both strings
    while i > 0 and j > 0:
        if str1[i - 1] == str2[j - 1]:
            # If the characters are the same, add them to the result string and move to the next character in both strings
            lcs += str1[i - 1]
            i -= 1
            j -= 1
        elif lcs_matrix[i - 1][j] > lcs_matrix[i][j - 1]:
            # If the length of the longest common subsequence of the substring that doesn't include the current character from str1 is greater than the length of the longest common subsequence of the substring that doesn't include the current character from str2,
            # move to the next character in str1
            i -= 1
        else:
            # Otherwise, move to the next character in str2
            j -= 1
    
    # Reverse the result string and return it
    return lcs[::-1]

if __name__ == "__main__":
    str1 = sys.stdin.readline().strip()
    str2 = sys.stdin.readline().strip()
    
    # Call the get_lcs method to find the longest common subsequence and print the result
    lcs = get_lcs(str1, str2)
    print("The Longest Common Subsequence is: " + lcs)

