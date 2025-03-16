

import re

def regexBU(src, pat):
    """
    Determines if the given source string matches the given pattern using bottom-up dynamic programming (tabulation).
    This method builds a solution iteratively by filling out a table, where each cell represents whether a substring
    of the source string matches a substring of the pattern.

    Time Complexity: O(N * M), where N is the length of the source string and M is the length of the pattern.
    Space Complexity: O(N * M) for the table used in the tabulation process.

    Args:
        src (str): The source string to be matched against the pattern.
        pat (str): The pattern containing wildcards ('*' matches a sequence of characters, '?' matches a single character).

    Returns:
        bool: True if the source string matches the pattern, False otherwise.
    """
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

                ans = False
                if chs == chp or chp == '?':
                    ans = strg[row + 1][col + 1]
                elif chp == '*':
                    blank = strg[row][col + 1]
                    multiple = strg[row + 1][col]
                    ans = blank or multiple
                strg[row][col] = ans
    return strg[0][0]

# 