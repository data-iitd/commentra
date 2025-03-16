n = int(input())
data = [int(x) for x in input().split()]
max = 0
index = 0
for i in range(n):
    if data[i] > max:
        max = data[i]
        index = i
a = 0
for i in range(n):
    if i!= index:
        a += data[i]
if a > max:
    print("Yes")
else:
    print("No")
#