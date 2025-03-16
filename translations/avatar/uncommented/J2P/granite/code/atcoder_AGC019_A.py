
Q, H, S, D = map(int, input().split())
N = int(input())
onePrice = min(Q * 4, H * 2, S)
if onePrice <= D // 2:
    print(N * onePrice)
else:
    print((N // 2) * D + (N % 2) * onePrice)
