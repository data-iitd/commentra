import math

a, b = map(int, input().split())
bstr = str(b)
num = a * (10 ** len(bstr)) + b

for i in range(1, 100101):
    if i * i == num:
        break
else:
    print("No")
    exit()

print("Yes")
# <END-OF-CODE>
