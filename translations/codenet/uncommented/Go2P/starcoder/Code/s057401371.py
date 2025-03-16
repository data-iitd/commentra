
import sys

s = sys.stdin.readline().strip()

d = ord('a') - ord('A')
for r in s:
    rr = r
    if ord('A') <= ord(r) <= ord('Z'):
        rr = chr(ord(r) + d)
    elif ord('a') <= ord(r) <= ord('z'):
        rr = chr(ord(r) - d)
    print(rr, end='')
print()

