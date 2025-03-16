
import sys

str = sys.stdin.readline().strip()
k = int(sys.stdin.readline().strip())
n = len(str)

for i in range(k):
    if str[i] == '1':
        if i == k - 1:
            print(1)
            break
    else:
        print(str[i])
        break

# 