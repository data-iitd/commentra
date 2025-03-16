def main():
    n = int(input())
    a = list(map(int, input().split()))
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
                    elif a[i + 1] > a[i + 2]:
                        isup = False
                    else:
                        issame = True
                    cnt += 1
                else:
                    cnt += 1
                    break

    print(cnt)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
