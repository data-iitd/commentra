def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    if a[0] < a[1]:
        isup = True
    elif a[0] > a[1]:
        isup = False
    else:
        issame = True
    
    cnt = 1
    i = 1
    while i < n - 1:
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
        i += 1
    
    print(cnt)

main()
