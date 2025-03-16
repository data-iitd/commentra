n = int(input())
h = []
max_height = -1
flag = 0

for i in range(n):
    height = int(input())
    h.append(height)
    if max_height < height:
        max_height = height

    if max_height - height >= 2:
        flag = 1

if flag == 1:
    print("No")
else:
    print("Yes")

# <END-OF-CODE>
