# -*- coding: utf-8 -*-

# 入場料金
# アイヅ温泉には、浴場とプールがあり、
# 浴場を利用するには入浴券(nyuyoku_ticket)を、
# プールを利用するにはプール券(pool_ticket)をそれぞれ買う必要があります。
# これらの券の値段は、日によって変わるかもしれません。
# また、アイヅ温泉には以下のようなルールがあります。
# 	券は購入当日１回の利用に限り有効。
# 	「入浴券５枚以上かつプール券２枚以上」でまとめて買うと、すべての券が２割引になる。
#
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
# １行目のN(1? N? 365)は料金を計算したい日数である。
# 続くN行に、i日目の入浴券の料金xi(100? xi? 1000)、
# プール券の料金yi(100? yi? 1000)、
# 使用する入浴券の枚数bi(0? bi? 6)、					←最大6人
# 使用するプール券の枚数pi(0? pi? 6)が与えられる。		←最大6人
# 入浴券とプール券共に料金は50円刻みである。
#
# それぞれの日について最も安い合計料金を１行に出力する。

# 入力
n = int( input() )

# 各日の入浴券とプール券の料金、使用数を入力
nyuyoku_ticket = [ int( input() ) for i in range( n ) ]
pool_ticket = [ int( input() ) for i in range( n ) ]
nyuyoku_member = [ int( input() ) for i in range( n ) ]
pool_member = [ int( input() ) for i in range( n ) ]

# 各日の最も安い合計料金を計算
seiki_ryoukin = [ ( ( ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10 for i in range( n ) ]
waribiki_ryoukin = [ ( ( ( nyuyoku_ticket[i] * 5 ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10 for i in range( n ) ]
saiyasune = [ seiki_ryoukin[i] if seiki_ryoukin[i] < waribiki_ryoukin[i] else waribiki_ryoukin[i] for i in range( n ) ]

# 各日の最も安い合計料金を出力
for i in range( n ):
	print( saiyasune[i] )

