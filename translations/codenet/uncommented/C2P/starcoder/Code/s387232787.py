
c = [0] * 26

while True:
    try:
        s = input()
        if not s:
            break
        for c in s:
            if 'a' <= c <= 'z':
                c = ord(c) - ord('a')
                c += 1
            elif 'A' <= c <= 'Z':
                c = ord(c) - ord('A')
                c += 1
            c -= 1
            c[c] += 1
    except EOFError:
        break

for i in range(26):
    print('a' + chr(i + ord('a')), ':', c[i])

#