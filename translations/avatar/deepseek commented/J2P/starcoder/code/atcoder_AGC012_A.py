
# <START-OF-CODE>

n = int(input())
array = [int(x) for x in input().split()]

array.sort()

head = len(array) - 2
res = 0

for i in range(n):
    res += array[head]
    head -= 2

print(res)

# 