def func(A):
    a = A.copy()
    min_val = 0
    i = 0
    while i < len(a):
        if a[i] == 0:
            a.pop(i)
            i -= 1
        else:
            if min_val != 0:
                a[i] = a[i] % min_val
                if a[i] == 1:
                    print(1)
                    exit()
            else:
                min_val = a[i]
        i += 1
    a.sort()
    return a


def main():
    n = int(input())
    a = []
    for _ in range(n):
        a.append(int(input()))
    a.sort()
    if a[-1] == 0:
        print(0)
        exit()
    ans = 0
    while True:
        if len(a) == 1:
            ans = a[0]
            break
        a = func(a)
    print(ans)


main()
