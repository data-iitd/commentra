
n = int(input())
sum = 0
min = 0
max = 0
for i in range(n):
    m = int(input())
    sum += m
    if i == 0:
        min = m
        max = m
    if min > m:
        min = m
    if max < m:
        max = m
print(min, max, sum)
