
# 入場料金
# アイヅ温泉には、浴場とプールがあり、
# 浴場を利用するには入浴券(nyuyoku_ticket)を、
# プールを利用するにはプール券(pool_ticket)をそれぞれ買う必要があります。
# これらの券の値段は、日によって変わるかもしれません。
# また、アイヅ温泉には以下のようなルールがあります。
# 	券は購入当日１回の利用に限り有効。
# 	「入浴券５枚以上かつプール券２枚以上」でまとめて買うと、すべての券が２割引になる。

# 温泉好きの貞吉さんとその友人たちは、アイヅ温泉に毎日のように通っています。
# 彼らは皆気まぐれで、日によって使う枚数は異なります。
# アイヅ温泉には割引ルールがあるため、グループで協力して上手に買えば、
# 合計料金を安く済ますことができるかもしれません。
# 
# 入浴券とプール券の料金、使用する入浴券の枚数とプール券の枚数が入力として与えられたとき、
# 最も安い合計料金を出力するプログラムを作成してください。
# ただし、使用する枚数より多く券を買うことで合計料金が安くなるなら、
# 買った券すべてを使わなくともよいものとします。
# 
# １行目のN(1 ? N ? 365)は料金を計算したい日数である。
# 続くN行に、i日目の入浴券の料金xi(100 ? xi ? 1000)、
# プール券の料金yi(100 ? yi ? 1000)、
# 使用する入浴券の枚数bi(0 ? bi ? 6)、					←最大6人
# 使用するプール券の枚数pi(0 ? pi ? 6)が与えられる。		←最大6人
# 入浴券とプール券共に料金は50円刻みである。
# 
# それぞれの日について最も安い合計料金を１行に出力する。

# 入場料金を入力受ける
n = int(input())

# 各日の入浴券とプール券の料金、使用数を入力受ける
nyuyoku_ticket = []
pool_ticket = []
nyuyoku_member = []
pool_member = []
for i in range(n):
    nyuyoku_ticket.append(int(input()))
    pool_ticket.append(int(input()))
    nyuyoku_member.append(int(input()))
    pool_member.append(int(input()))

# 割引ルールをチェックして、最も安い合計料金を計算
seiki_ryoukin = []
waribiki_ryoukin = []
saiyasune = []
for i in range(n):
    if nyuyoku_member[i] >= 5 and pool_member[i] >= 2:
        seiki_ryoukin.append(((nyuyoku_ticket[i] * nyuyoku_member[i]) + (pool_ticket[i] * pool_member[i])) * 8 // 10)
        saiyasune.append(seiki_ryoukin[i])
    elif nyuyoku_member[i] >= 5:
        seiki_ryoukin.append(nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
        waribiki_ryoukin.append(((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune.append(waribiki_ryoukin[i])
        else:
            saiyasune.append(seiki_ryoukin[i])
    elif pool_member[i] >= 2:
        seiki_ryoukin.append(nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
        waribiki_ryoukin.append(((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * pool_member[i])) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune.append(waribiki_ryoukin[i])
        else:
            saiyasune.append(seiki_ryoukin[i])
    else:
        seiki_ryoukin.append(nyuyoku_ticket[i] * nyuyoku_member[i] + pool_ticket[i] * pool_member[i])
        waribiki_ryoukin.append(((nyuyoku_ticket[i] * 5) + (pool_ticket[i] * 2)) * 8 // 10)
        if seiki_ryoukin[i] >= waribiki_ryoukin[i]:
            saiyasune.append(waribiki_ryoukin[i])
        else:
            saiyasune.append(seiki_ryoukin[i])

# 各日の最も安い合計料金を出力
for i in range(n):
    print(saiyasune[i])

# 