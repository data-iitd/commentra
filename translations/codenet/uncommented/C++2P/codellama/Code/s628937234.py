
import sys
s = sys.stdin.readline().strip()
t = s[0]
t += str(len(s)-2)
t += s[-1]
print(t)

