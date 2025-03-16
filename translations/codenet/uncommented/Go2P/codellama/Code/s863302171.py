
import sys

n = sys.stdin.readline().strip()

for i in range(3):
    if n[i] == '7':
        print("Yes")
        break
else:
    print("No")

