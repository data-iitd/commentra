import sys

def main():
    N = int(sys.stdin.readline())
    i = 357
    c = 0
    while i <= N:
        s = str(i)
        if '3' in s and '5' in s and '7' in s:
            c += 1
        sb = ''
        f = False
        for j in range(len(s)):
            a = s[len(s) - 1 - j]
            if f:
                sb += a
            else:
                if a == '3':
                    sb += '5'
                    f = True
                elif a == '5':
                    sb += '7'
                    f = True
                else:
                    sb += '3'
        if not f:
            sb += '3'
        sb2 = sb[::-1]
        i = int(sb2)
    print(c)

if __name__ == "__main__":
    main()

