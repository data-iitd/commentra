

n = int(input())
a = list(map(int, input().split()))
a.sort()
min_a = a[0]
for value in a:
    if value % min_a!= 0:
        print(-1)
        break
else:
    print(min_a)
