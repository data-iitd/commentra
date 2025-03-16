package main

import (
	"fmt"
)

const DAYS = 365 // 最大何日か？

func main() {
	var n, i int
	var nyuyokuTicket [DAYS]int
	var poolTicket [DAYS]int
	var nyuyokuMember [DAYS]int
	var poolMember [DAYS]int
	var seikiRyoukin [DAYS]int
	var waribikiRyoukin [DAYS]int
	var saiyasune [DAYS]int

	// 入場料金を入力受ける
	fmt.Scan(&n)

	// 各日の入浴券とプール券の料金、使用数を入力受ける
	for i = 0; i < n; i++ {
		fmt.Scan(&nyuyokuTicket[i], &poolTicket[i], &nyuyokuMember[i], &poolMember[i])

		// 割引ルールをチェックして、最も安い合計料金を計算
		if nyuyokuMember[i] >= 5 && poolMember[i] >= 2 {
			seikiRyoukin := (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]) * 8 / 10
			saiyasune[i] = seikiRyoukin
		} else if nyuyokuMember[i] >= 5 {
			seikiRyoukin := nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			waribikiRyoukin := (nyuyokuTicket[i]*5+poolTicket[i]*poolMember[i])*8/10
			if seikiRyoukin >= waribikiRyoukin {
				saiyasune[i] = waribikiRyoukin
			} else {
				saiyasune[i] = seikiRyoukin
			}
		} else if poolMember[i] >= 2 {
			seikiRyoukin := nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			waribikiRyoukin := (nyuyokuTicket[i]*5+poolTicket[i]*poolMember[i])*8/10
			if seikiRyoukin >= waribikiRyoukin {
				saiyasune[i] = waribikiRyoukin
			} else {
				saiyasune[i] = seikiRyoukin
			}
		} else {
			seikiRyoukin := nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			waribikiRyoukin := (nyuyokuTicket[i]*5+poolTicket[i]*2)*8/10
			if seikiRyoukin >= waribikiRyoukin {
				saiyasune[i] = waribikiRyoukin
			} else {
				saiyasune[i] = seikiRyoukin
			}
		}
	}

	// 各日の最も安い合計料金を出力
	for i = 0; i < n; i++ {
		fmt.Println(saiyasune[i])
	}
}

