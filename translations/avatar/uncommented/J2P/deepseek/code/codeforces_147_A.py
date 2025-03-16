def is_latin_letter(c):
    return 'a' <= c <= 'z'

def is_punctuation(c):
    return c in ['.', ',', '!', '?']

def main():
    import sys
    input = sys.stdin.readline
    print = sys.stdout.write
    s = input().strip()
    sb = []
    n = len(s)
    sb.append(s[0])
    for i in range(1, n):
        c = s[i]
        if is_latin_letter(c):
            if not is_latin_letter(s[i - 1]):
                sb.append(' ')
            sb.append(c)
        elif is_punctuation(c):
            sb.append(c)
    print(''.join(sb))

if __name__ == "__main__":
    main()
