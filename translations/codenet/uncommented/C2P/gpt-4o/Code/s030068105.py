n = int(input().strip())
data = list(map(int, input().strip().split()))

max_value = 0
index = -1

for i in range(n):
    if data[i] > max_value:
        max_value = data[i]
        index = i

a = 0
for i in range(n):
    if i != index:
        a += data[i]

if a > max_value:
    print("Yes")
else:
    print("No")

# <END-OF-CODE>
