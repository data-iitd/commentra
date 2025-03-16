
# <START-OF-CODE>

n = int(input())
levels = int(input())
sum = 0
sum2 = 0
sum3 = 0
arr = [0] * levels
count = 0
for i in range(levels):
    arr[i] = int(input())
level2 = int(input())
level3 = levels + level2
arr2 = [0] * level3
for i in range(arr.length):
    arr2[i] = arr[i]
for i in range(arr.length, level3):
    arr2[i] = int(input())
arr3 = [0] * n
j = 0
for i in range(n):
    arr3[i] = j + 1
    j += 1
for i in range(n):
    for x in range(arr2.length):
        if arr3[i] == arr2[x]:
            count += 1
            break
if count == n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")

# 