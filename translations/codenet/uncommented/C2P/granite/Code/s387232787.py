
c = [0] * 26
while True:
    try:
        s = input()
        for c in s:
            if 'a' <= c and c <= 'z':
                c[ord(c) - ord('a')] += 1
            elif 'A' <= c and c <= 'Z':
                c[ord(c) - ord('A')] += 1
    except:
        break
for i in range(26):
    print(chr(ord('a') + i), ':', c[i])
