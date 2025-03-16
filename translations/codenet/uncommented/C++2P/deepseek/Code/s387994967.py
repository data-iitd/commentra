A, B = map(int, input().split())
if A < 13 and A >= 6:
    print(B // 2)
elif A < 6:
    print(0)
elif A >= 13:
    print(B)
