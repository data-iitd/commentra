
while True:
    an = [int(x) for x in input().split()]
    L = an[1]
    if L == 0:
        break
    aj = an[0]
    end = 0
    for k in range(2, 21):
        a1 = [int(x) for x in str(aj)]
        a2 = [int(x) for x in str(aj)]
        a1.sort()
        a2.sort(reverse=True)
        d = 1
        max = 0
        min = 0
        for i in range(L-1, -1, -1):
            max += a1[i] * d
            min += a2[i] * d
            d *= 10
        def = max - min
        for i in range(k):
            if def == an[i]:
                print(i, def, k-i)
                end = 1
                break
        if end == 1:
            break
        an.append(def)
        aj = def
    print("