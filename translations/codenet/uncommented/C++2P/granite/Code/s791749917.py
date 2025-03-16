
H, W = map(int, input().split())

ans = 1
if H!= 1 and W!= 1:
    ans = (H * W + 1) // 2

print(ans)
