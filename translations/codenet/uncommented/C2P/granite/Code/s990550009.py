
n = int(input())
a = list(map(int, input().split()))
cnt = 1
isup = a[0] < a[1]
issame = False
for i in range(1, n - 1):
    if issame:
        if a[i]!= a[i + 1]:
            issame = False
            isup = a[i] < a[i + 1]
    else:
        if isup and a[i] <= a[i + 1]:
            pass
        elif not isup and a[i] >= a[i + 1]:
            pass
        else:
            if i + 2 < n:
                if a[i + 1] < a[i + 2]:
                    isup = True
                else:
                    isup = False
                cnt += 1
            else:
                cnt += 1
                break
print(cnt)

