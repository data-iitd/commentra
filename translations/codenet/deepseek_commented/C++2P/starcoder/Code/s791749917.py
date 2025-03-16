H, W = map(int, input().split())
if H == 1 or W == 1:
    print(1)
else:
    m = H*W
    if m % 2 == 0:
        print(m//2)
    else:
        print((m+1)//2)
# 