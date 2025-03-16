
n = int(input())
x = list(map(int, input().split()))
q = int(input())
y = list(map(int, input().split()))

count = 0
for i in range(q):
    for j in range(n):
        if y[i] == x[j]:
            count += 1
            break

print(count)

