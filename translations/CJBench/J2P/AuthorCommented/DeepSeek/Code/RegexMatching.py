def regexBU(src, pat):
    n = len(src)
    m = len(pat)
    strg = [[False] * (m + 1) for _ in range(n + 1)]
    strg[n][m] = True
    for row in range(n, -1, -1):
        for col in range(m - 1, -1, -1):
            if row == n:
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

# Main function to take input and output the result
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    src = data[0]
    pat = data[1]
    isMatch = regexBU(src, pat)
    print("Does the source string match the pattern? " + str(isMatch))

if __name__ == "__main__":
    main()
