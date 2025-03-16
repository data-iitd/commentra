
import sys

n = int(input())
k = int(input())
a = input()

if k > n // 2:
    while k < n:
        print("RIGHT")
        k += 1
else:
    while k > 1:
        print("LEFT")
        k -= 1

if k == 1:
    for i in range(len(a)):
        print("PRINT", a[i])
        if i < len(a) - 1:
            print("RIGHT")
else:
    for i in range(len(a) - 1, -1, -1):
        print("PRINT", a[i])
        if i > 0:
            print("LEFT")

print("