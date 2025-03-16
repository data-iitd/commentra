
# 入場料金
n = int(input())
nyuyoku_ticket = []
pool_ticket = []
nyuyoku_member = []
pool_member = []
seiki_ryoukin = []
waribiki_ryoukin = []
saiya_sune = []

# 各日の入浴券とプール券の料金、使用数を入力受け
for i in range(n):
    nyuyoku_ticket.append(int(input()))
    pool_ticket.append(int(input()))
    nyuyoku_member.append(int(input()))
    pool_member.append(int(input()))

    # 割引ルールをチェックして、最も安い合計料金を計算
    if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
        seiki_ryoukin.append(((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])) * 8 // 10)
        saiya_sune.append(seiki_ryoukin[i])
    elif nyuyoku_member[i] >= 5:
        seiki_ryoukin.append((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]))
        waribiki_ryoukin.append(((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiya_sune.append(waribiki_ryoukin[i])
        else:
            saiya_sune.append(seiki_ryoukin[i])
    elif pool_member[i] >= 2:
        seiki_ryoukin.append((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]))
        waribiki_ryoukin.append(((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiya_sune.append(waribiki_ryoukin[i])
        else:
            saiya_sune.append(seiki_ryoukin[i])
    else:
        seiki_ryoukin.append((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]))
        waribiki_ryoukin.append(((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * 2)) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiya_sune.append(waribiki_ryoukin[i])
        else:
            saiya_sune.append(seiki_ryoukin[i])

# 各日の最も安い合計料金を OUTPUT
for i in range(n):
    print(saiya_sune[i])

