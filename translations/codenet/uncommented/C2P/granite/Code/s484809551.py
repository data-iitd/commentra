
import sys

def strrstr(string, pattern):
    offset = 0
    lastP = None

    searchResult = None
    while (searchResult = string.find(pattern, offset))!= -1 and string[offset]!= '\0':
        lastP = searchResult
        offset += 1

    return lastP

def compare_f(a, b):
    return a < b

def comb(n, r):
    result = 1

    for i in range(r):
        result *= n - i
        result /= i + 1

    return result

def gcd(m, n):
    temp = n

    while m % n!= 0:
        temp = n
        n = m % n
        m = temp

    return n

if __name__ == "__main__":
    patternBase = "keyence"
    top = ""
    bottom = ""
    S = ""

    S = input()

    lenS = len(S)
    found = False

    for offset in range(len(patternBase)):
        top = patternBase[:offset]
        bottom = patternBase[offset:]

        topSearch = S.find(top)
        if topSearch!= -1:
            bottomSearch = strrstr(S[topSearch + offset:], bottom)
            if bottomSearch!= -1:
                sepCount = 0

                if topSearch!= 0:
                    sepCount += 1
                if topSearch + offset!= bottomSearch:
                    sepCount += 1
                if bottomSearch[len(bottom)]!= '\0':
                    sepCount += 1

                if sepCount <= 1:
                    found = True
                    break

    print("YES" if found else "NO")

