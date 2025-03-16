import sys
n = int(sys.stdin.readline())
levels = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
level2 = int(sys.stdin.readline())
level3 = levels + level2
arr2 = list(map(int, sys.stdin.readline().split()))
arr3 = list(range(1, n+1))
count = 0
for i in range(n):
    for x in range(level3):
        if arr3[i] == arr2[x]:
            count += 1
            break
if count == n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")
