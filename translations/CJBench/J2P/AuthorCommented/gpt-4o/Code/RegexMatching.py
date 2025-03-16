class WildcardMatcher:
    @staticmethod
    def regexBU(src: str, pat: str) -> bool:
        strg = [[False] * (len(pat) + 1) for _ in range(len(src) + 1)]
        strg[len(src)][len(pat)] = True
        
        for row in range(len(src), -1, -1):
            for col in range(len(pat) - 1, -1, -1):
                if row == len(src):
                    if pat[col] == '*':
                        strg[row][col] = strg[row][col + 1]
                    else:
                        strg[row][col] = False
                else:
                    chs = src[row]
                    chp = pat[col]

                    if chs == chp or chp == '?':
                        strg[row][col] = strg[row + 1][col + 1]
                    elif chp == '*':
                        blank = strg[row][col + 1]
                        multiple = strg[row + 1][col]
                        strg[row][col] = blank or multiple
                    else:
                        strg[row][col] = False
        
        return strg[0][0]


if __name__ == "__main__":
    src = input("Enter the source string: ")
    pat = input("Enter the pattern string: ")

    is_match = WildcardMatcher.regexBU(src, pat)

    print("Does the source string match the pattern? " + str(is_match))

# <END-OF-CODE>
