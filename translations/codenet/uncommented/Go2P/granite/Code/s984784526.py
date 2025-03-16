
a = list(map(int, input().split()))

five = 0
seven = 0

for i in a:
    if i == 5:
        five += 1
    if i == 7:
        seven += 1

if five == 2 and seven == 1:
    print("YES")
else:
    print("NO")

