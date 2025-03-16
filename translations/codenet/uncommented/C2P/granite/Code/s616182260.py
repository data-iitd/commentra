
c = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
for i in range(3):
    c[i] = list(map(int, input().split()))

a = [0, 0, 0]
b = [c[0][i] for i in range(3)]
for i in range(1, 3):
    a[i] = c[i][0] - b[0]

for i in range(3):
    for j in range(3):
        if c[i][j]!= a[i] + b[j]:
            print("No")
            exit()

print("Yes")

