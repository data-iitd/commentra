n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
sum = 0
for i in range(n):
    if a[i] - b[i] > 0:
        sum += a[i] - b[i]
print(sum)
#