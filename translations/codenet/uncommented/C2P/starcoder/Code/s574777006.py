
n = int(input())
x = [int(input()) for i in range(n)]
q = int(input())
y = [int(input()) for i in range(q)]

sum = 0
for i in y:
    if i in x:
        sum += 1

print(sum)

