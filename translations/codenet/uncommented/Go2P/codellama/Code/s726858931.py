
import sys

s = sys.stdin.readline().strip()

c = 'a'

for j in range(26):
    found = False
    for i in range(len(s)):
        if s[i] == c:
            found = True
            break
    if found == False:
        print(c)
        break
    c = chr(ord(c) + 1)

else:
    print("None")

