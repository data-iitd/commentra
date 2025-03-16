DAYS = 365  # 最大何日か？

def main():
    n = int(input())
    nyuyoku_ticket = [0] * DAYS
    pool_ticket = [0] * DAYS
    nyuyoku_member = [0] * DAYS
    pool_member = [0] * DAYS
    saiyasune = [0] * DAYS

    # 入場料金を入力受ける
    for i in range(n):
        x, y, b, p = map(int, input().split())
        nyuyoku_ticket[i] = x
        pool_ticket[i] = y
        nyuyoku_member[i] = b
        pool_member[i] = p

        # 割引ルールをチェックして、最も安い合計料金を計算
        if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
            seiki_ryoukin = ((nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]) * 8) // 10
            saiyasune[i] = seiki_ryoukin
        elif nyuyoku_member[i] >= 5:
            seiki_ryoukin = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin = ((nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin, waribiki_ryoukin)
        elif pool_member[i] >= 2:
            seiki_ryoukin = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin = ((nyuyoku_ticket[i] * 5 + pool_ticket[i] * pool_member[i]) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin, waribiki_ryoukin)
        else:
            seiki_ryoukin = nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i]
            waribiki_ryoukin = ((nyuyoku_ticket[i] * 5 + pool_ticket[i] * 2) * 8) // 10
            saiyasune[i] = min(seiki_ryoukin, waribiki_ryoukin)

    # 各日の最も安い合計料金を出力
    for i in range(n):
        print(saiyasune[i])

main()
