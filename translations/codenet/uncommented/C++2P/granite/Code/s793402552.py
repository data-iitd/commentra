
import math

a, b = map(int, input().split())
num = a * 10 ** len(str(b)) + b

for i in range(1, 100101):
    if i * i == num:
        print("Yes")
        break
else:
    print("No")

