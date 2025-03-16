def count_segments(n, a):
    cnt = 1
    isup = None
    issame = False

    if a[0] < a[1]:
        isup = True
    elif a[0] > a[1]:
        isup = False
    else:
        issame = True

    for i in range(1, n - 1):
        if issame:
            if a[i] != a[i + 1]:
                issame = False
                if a[i] < a[i + 1]:
                    isup = True
                else:
                    isup = False
        else:
            if isup and a[i] <= a[i + 1]:
                pass
            elif not isup and a[i] >= a[i + 1]:
                pass
            else:
                if i + 2 < n:
                    if a[i + 1] < a[i + 2]:
                        isup = True
                    elif a[i + 1] > a[i + 2]:
                        isup = False
                    else:
                        issame = True
                    cnt += 1
                else:
                    cnt += 1
                    break

    return cnt

# Read input
n = int(input())
a = list(map(int, input().split()))

# Output the total number of segments
print(count_segments(n, a))
