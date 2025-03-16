import sys

def gs():
    return input()

def gi():
    return int(input())

def gl():
    return int(input())

def gd():
    return float(input())

def main():
    scanner = sys.stdin
    N = gi()

    i = 357
    c = 0

    while i <= N:
        s = str(i)

        if '3' in s and '5' in s and '7' in s:
            c += 1

        sb = []
        f = False

        for j in range(len(s)):
            a = s[len(s) - 1 - j]

            if f:
                sb.append(a)
            else:
                if a == '3':
                    sb.append('5')
                    f = True
                elif a == '5':
                    sb.append('7')
                    f = True
                else:
                    sb.append('3')
                    f = True

        if not f:
            sb.append('3')

        sb2 = ''.join(reversed(sb))
        i = int(sb2)

    print(c)

if __name__ == "__main__":
    main()

