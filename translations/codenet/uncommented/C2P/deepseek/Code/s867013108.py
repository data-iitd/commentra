DAYS = 365  # 最大何日か？

def main():
    n = int(input())
    nyuyoku_ticket = [0] * DAYS
    pool_ticket = [0] * DAYS
    nyuyoku_member = [0] * DAYS
    pool_member = [0] * DAYS
    saiyasune = [0] * DAYS

    for i in range(n):
        nyuyoku_ticket[i], pool_ticket[i], nyuyoku_member[i], pool_member[i] = map(int, input().split())
        if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
            seiki_ryoukin = ((nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8) // 10
            saiyasune[i] = seiki_ryoukin
        elif nyuyoku_member[i] >= 5:
            seiki_ryoukin = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin = ((nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * 2) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin, waribiki_ryoukin)
        elif pool_member[i] >= 2:
            seiki_ryoukin = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin = ((nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin, waribiki_ryoukin)
        else:
            seiki_ryoukin = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin = ((nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin, waribiki_ryoukin)

    for i in range(n):
        print(saiyasune[i])

main()
