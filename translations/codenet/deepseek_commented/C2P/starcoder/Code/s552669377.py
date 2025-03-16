# <START-OF-CODE>

n = int(input())

min = 1000000
max = -1000000
sum = 0

for i in range(n):
    tmp = int(input())
    if min > tmp:
        min = tmp
    if max < tmp:
        max = tmp
    sum += tmp

print(min, max, sum)

# 