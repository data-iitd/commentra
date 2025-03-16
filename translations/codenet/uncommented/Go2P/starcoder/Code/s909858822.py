A, B = map(int, input().split())

ans = 0
if 6 <= A and A <= 12:
    ans = B // 2
elif 12 < A:
    ans = B

print(ans)

