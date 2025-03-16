
import sys

n = int(sys.stdin.readline())
s = ""

# Converting the integer to binary representation
while n > 0:
    x = n % 2
    n //= 2
    s += str(x)

ans = 0

# Counting the number of '1's in the binary representation
for i in range(len(s)):
    if s[i] == '1':
        ans += 1

print(ans)

