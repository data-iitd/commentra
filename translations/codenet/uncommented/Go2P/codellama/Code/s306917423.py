
import sys

s = sys.stdin.readline().strip()
ans = 0
for c in s:
    if c == '1':
        ans += 1
print(ans)

