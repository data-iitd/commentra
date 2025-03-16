
n = int(input())
k = int(input())
arr = list(map(int, input().split()))
arr.sort()
set = set()
count = 0
for i in range(n):
    if arr[i] % k!= 0:
        count += 1
        set.add(arr[i])
    elif arr[i] // k not in set:
        count += 1
        set.add(arr[i])
print(count)
