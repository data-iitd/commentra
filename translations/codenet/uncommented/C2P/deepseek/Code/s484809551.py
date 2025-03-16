import sys

def strrstr(string, pattern):
    offset = 0
    lastP = None

    while True:
        searchResult = string.find(pattern, offset)
        if searchResult == -1 or string[offset] == '\0':
            break
        lastP = searchResult
        offset += 1

    return lastP

def compare_f(a, b):
    return -1 if a < b else 1

def comb(n, r):
    result = 1

    for i in range(r):
        result *= n - i
        result //= i + 1

    return result

def gcd(m, n):
    while m % n != 0:
        temp = n
        n = m % n
        m = temp

    return n

if __name__ == "__main__":
    patternBase = "keyence"
    top = [None] * 8
    bottom = [None] * 8
    S = sys.stdin.readline().strip()

    len_S = len(S)
    found = False

    for offset in range(len(patternBase) + 1):
        top[:offset] = patternBase[:offset]
        bottom[len(patternBase) - offset:] = patternBase[offset:]

        topSearch = S.find(''.join(top))
        if topSearch != -1:
            bottomSearch = strrstr(S[topSearch + offset:], ''.join(bottom))
            if bottomSearch != -1:
                sepCount = 0

                if topSearch != 0:
                    sepCount += 1
                if topSearch + offset != bottomSearch:
                    sepCount += 1
                if bottomSearch + len(bottom) != len_S:
                    sepCount += 1

                if sepCount <= 1:
                    found = True
                    break

    print("YES" if found else "NO")
