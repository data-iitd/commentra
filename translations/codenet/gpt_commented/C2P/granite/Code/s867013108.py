
n = int(input())
nyuyoku_ticket = []
pool_ticket = []
nyuyoku_member = []
pool_member = []
seiki_ryoukin = []
waribiki_ryoukin = []
saiya_sune = []

for i in range(n):
    x, y, b, p = map(int, input().split())
    nyuyoku_ticket.append(x)
    pool_ticket.append(y)
    nyuyoku_member.append(b)
    pool_member.append(p)

    if b >= 5 and p >= 2:
        seiki_ryoukin.append((x * b + y * p) * 8 // 10)
        saiya_sune.append(seiki_ryoukin[i])
    elif b >= 5:
        seiki_ryoukin.append(x * b + y * p)
        waribiki_ryoukin.append((x * 5 + y * 2) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiya_sune.append(waribiki_ryoukin[i])
        else:
            saiya_sune.append(seiki_ryoukin[i])
    elif p >= 2:
        seiki_ryoukin.append(x * b + y * p)
        waribiki_ryoukin.append((x * 5 + y * p) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiya_sune.append(waribiki_ryoukin[i])
        else:
            saiya_sune.append(seiki_ryoukin[i])
    else:
        seiki_ryoukin.append(x * b + y * p)
        waribiki_ryoukin.append((x * 5 + y * 2) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiya_sune.append(waribiki_ryoukin[i])
        else:
            saiya_sune.append(seiki_ryoukin[i])

for i in range(n):
    print(saiya_sune[i])

