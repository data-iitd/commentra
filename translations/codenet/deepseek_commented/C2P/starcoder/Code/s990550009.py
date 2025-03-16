# <START-OF-CODE>

n = int(input())
a = [int(x) for x in input().split()]

if a[0] < a[1]:
    isup = True
elif a[0] > a[1]:
    isup = False
else:
    isup = None

if isup is None:
    print(1)
else:
    cnt = 1
    for i in range(1, n - 1):
        if isup:
            if a[i] <= a[i + 1]:
                pass
            else:
                isup = False
                cnt += 1
        else:
            if a[i] >= a[i + 1]:
                pass
            else:
                isup = True
                cnt += 1
    print(cnt)

# 