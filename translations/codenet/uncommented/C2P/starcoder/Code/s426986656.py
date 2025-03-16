
A, B = map(int, input().split())

flag = 0
for i in range(1, 4):
    if ((A * B * i) % 2 == 1):
        flag = 1
        break

if (flag):
    print("Yes")
else:
    print("No")

# 