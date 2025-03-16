

a = [0, 0, 0]

for i in range(3):
    a[i] = int(input())

five = 0
seven = 0

for i in range(3):
    if a[i] == 5:
        five += 1
    if a[i] == 7:
        seven += 1

if five == 2 and seven == 1:
    print("YES")
else:
    print("NO")

