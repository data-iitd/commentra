
len = int(input())
a = [int(x) for x in input().split()]

for j in range(1, len):
    key = a[j]
    for i in range(j - 1, -1, -1):
        if a[i] > key:
            a[i + 1] = a[i]
        else:
            break
    a[i + 1] = key

print(*a)

