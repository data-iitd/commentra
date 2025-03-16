
import sys

s = sys.stdin.readline().strip()

for i in range(len(s)):
    if s[i+1:].find(s[i]) != -1:
        print("no")
        sys.exit(0)

print("yes")

