
import sys

def isLatinLetter(c):
    return c >= 'a' and c <= 'z'

def isPunctuation(c):
    if c == '.':
        return True
    if c == ',':
        return True
    if c == '!':
        return True
    if c == '?':
        return True
    return False

def main():
    br = sys.stdin
    pw = sys.stdout
    s = br.readline()
    sb = ''
    n = len(s)
    sb += s[0]
    for i in range(1, n):
        c = s[i]
        if isLatinLetter(c):
            if not isLatinLetter(s[i - 1]):
                sb +=''
            sb += c
        elif isPunctuation(c):
            sb += c
    pw.write(sb)
    pw.flush()
    pw.close()

if __name__ == '__main__':
    main()

