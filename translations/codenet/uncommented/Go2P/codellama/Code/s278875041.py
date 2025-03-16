
import sys

a = sys.stdin.readline().strip()
tmp = a.replace("1", "0")
b = tmp.replace("9", "1")
ans = b.replace("0", "9")
print(ans)

