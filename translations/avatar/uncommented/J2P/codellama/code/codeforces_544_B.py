
import sys

n = int(sys.stdin.readline().strip())
count = int(sys.stdin.readline().strip())

a = (n + 1) // 2
b = n // 2
max = a * a + b * b

if count > max:
    print("NO")
    sys.exit()

print("YES")

for i in range(n):
    sb = ""
    for j in range(n):
        if (i + j) % 2 == 0 and count > 0:
            sb += "L"
            count -= 1
        else:
            sb += "S"
    print(sb)

