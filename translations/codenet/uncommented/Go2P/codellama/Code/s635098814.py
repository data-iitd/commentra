
import sys

def main():
    str = sys.stdin.readline().rstrip()
    S = list(str)
    if len(S) == 0:
        return
    memo = [0] * 26
    for i in range(len(S)):
        c = S[i]
        if 'a' <= c and c <= 'z':
            # toUpper
            # c-('a'-'A')
            memo[ord(c)-ord('a')] += 1
        elif 'A' <= c and c <= 'Z':
            # toLower
            # c+('a'-'A')
            memo[ord(c)-ord('A')] += 1
        else:
            # stay
            # c
            continue
    for i in range(26):
        print(chr(i+ord('a')), ':', memo[i])

if __name__ == '__main__':
    main()

