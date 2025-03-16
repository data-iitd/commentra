MAX_N = 1000  # maximum size of the array

while True:
    try:
        m, nmi, nma = map(int, input().split())
        if nmi == 0:
            break
        data = list(map(int, input().split()))
        ma = 0
        ans = 0
        for i in range(nmi - 1, nma):
            if ma <= data[i] - data[i + 1]:
                ans = i + 1
                ma = data[i] - data[i + 1]
        print(ans)
    except EOFError:
        break

