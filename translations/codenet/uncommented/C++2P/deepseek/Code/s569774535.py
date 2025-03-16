n = int(input())
a = list(map(int, input().split()))

ans = 0
ok = True
while ok:
    for i in range(n):
        if a[i] % 2 == 1:
            print(ans)
            ok = False
            break
        else:
            a[i] //= 2
    if ok:
        ans += 1

print(ans)
