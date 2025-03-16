
# <START-OF-CODE>
n = int(input())
count = int(input())

a = (n + 1) // 2
b = n // 2
max = a * a + b * b

if count > max:
    print("NO")
    exit()

print("YES")

for i in range(n):
    s = ""
    for j in range(n):
        if (i + j) % 2 == 0 and count > 0:
            s += "L"
            count -= 1
        else:
            s += "S"
    print(s)
# 