
import sys

def main():
    n = int(input())
    nyuyoku_ticket = []
    pool_ticket = []
    nyuyoku_member = []
    pool_member = []
    seiki_ryoukin = []
    waribiki_ryoukin = []
    saiyasune = []

    for i in range(n):
        line = input().split()
        nyuyoku_ticket.append(int(line[0]))
        pool_ticket.append(int(line[1]))
        nyuyoku_member.append(int(line[2]))
        pool_member.append(int(line[3]))

        if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
            seiki_ryoukin.append((((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])) * 8) // 10)
            saiyasune.append(seiki_ryoukin[i])
        elif nyuyoku_member[i] >= 5:
            seiki_ryoukin.append((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]))
            waribiki_ryoukin.append((((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * 2)) * 8) // 10)
            if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
                saiyasune.append(waribiki_ryoukin[i])
            else:
                saiyasune.append(seiki_ryoukin[i])
        elif pool_member[i] >= 2:
            seiki_ryoukin.append((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]))
            waribiki_ryoukin.append((((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8) // 10)
            if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
                saiyasune.append(waribiki_ryoukin[i])
            else:
                saiyasune.append(seiki_ryoukin[i])
        else:
            seiki_ryoukin.append((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i]))
            waribiki_ryoukin.append((((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * 2)) * 8) // 10)
            if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
                saiyasune.append(waribiki_ryoukin[i])
            else:
                saiyasune.append(seiki_ryoukin[i])

    for i in range(n):
        print(saiyasune[i])

if __name__ == "__main__":
    main()

