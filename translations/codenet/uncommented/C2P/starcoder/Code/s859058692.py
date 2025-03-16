
n = int(input())
sum = 0
min = 1000000000
max = -1000000000
for i in range(n):
    m = int(input())
    sum += m
    if min > m:
        min = m
    if max < m:
        max = m
print(min, max, sum)

