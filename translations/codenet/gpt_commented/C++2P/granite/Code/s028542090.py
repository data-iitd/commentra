
k = int(input())
a = list(map(int, input().split()))

max = 3
min = 2

if a[-1]!= 2:
    print(-1)
    exit(0)

for i in range(k - 2, -1, -1):
    if a[i] > max:
        print(-1)
        exit(0)
    else:
        max = ((max // a[i]) + 1) * a[i] - 1
        if min % a[i]!= 0:
            min = ((min // a[i]) + 1) * a[i]

    if max <= min:
        print(-1)
        exit(0)

print(min, max)

