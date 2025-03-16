

import sys

def is_latin_letter(c):
    return c >= 'a' and c <= 'z'

def is_punctuation(c):
    return c == '.' or c == ',' or c == '!' or c == '?'

def main():
    s = input()
    sb = []
    sb.append(s[0])
    for i in range(1, len(s)):
        c = s[i]
        if is_latin_letter(c):
            if not is_latin_letter(s[i - 1]):
                sb.append(' ')
            sb.append(c)
        elif is_punctuation(c):
            sb.append(c)
    print(''.join(sb))

if __name__ == '__main__':
    main()

