class Main:
    @staticmethod
    def get_lcs(str1, str2):
        if str1 is None or str2 is None:
            return None
        if len(str1) == 0 or len(str2) == 0:
            return ""
        
        lcs_matrix = [[0] * (len(str2) + 1) for _ in range(len(str1) + 1)]
        
        for i in range(1, len(str1) + 1):
            for j in range(1, len(str2) + 1):
                if str1[i - 1] == str2[j - 1]:
                    lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1
                else:
                    lcs_matrix[i][j] = max(lcs_matrix[i - 1][j], lcs_matrix[i][j - 1])
        
        return Main.lcs_string(str1, str2, lcs_matrix)

    @staticmethod
    def lcs_string(str1, str2, lcs_matrix):
        lcs = []
        i, j = len(str1), len(str2)
        
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

if __name__ == "__main__":
    str1 = input()
    str2 = input()
    lcs = Main.get_lcs(str1, str2)
    print("The Longest Common Subsequence is:", lcs)

# <END-OF-CODE>
