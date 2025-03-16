
import sys

n = int(sys.stdin.readline().strip())

s = ""

while n > 0:
    x = n % 2
    n = n // 2
    s += str(x)

ans = 0

for i in range(len(s)):
    if s[i] == "1":
        ans += 1

print(ans)

