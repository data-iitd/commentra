
import sys

def is_latin_letter(c):
    return c >= 'a' and c <= 'z'

def is_punctuation(c):
    if c == '.':
        return True
    elif c == ',':
        return True
    elif c == '!':
        return True
    elif c == '?':
        return True
    else:
        return False

if __name__ == '__main__':
    s = sys.stdin.readline()
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

