

import sys


def regex_bu(src, pat):
    strg = [[False for _ in range(len(pat) + 1)] for _ in range(len(src) + 1)]
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
                    ans = strg[row + 1][col + 1]
                elif chp == '*':
                    blank = strg[row][col + 1]
                    multiple = strg[row + 1][col]
                    ans = blank or multiple
                else:
                    ans = False
                strg[row][col] = ans
    return strg[0][0]


if __name__ == '__main__':
    src = sys.stdin.readline().strip()
    pat = sys.stdin.readline().strip()
    print(regex_bu(src, pat))


# 