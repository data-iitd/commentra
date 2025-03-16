package main

import (
	"fmt"
)

const DAYS = 365 // 最大何日か？

func main() {
	var n int
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
	for i := 0; i < n; i++ {
		fmt.Scan(&nyuyokuTicket[i], &poolTicket[i], &nyuyokuMember[i], &poolMember[i])

		// 割引ルールをチェックして、最も安い合計料金を計算
		if nyuyokuMember[i] >= 5 && poolMember[i] >= 2 {
			seikiRyoukin[i] = (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]) * 8 / 10
			saiyasune[i] = seikiRyoukin[i]
		} else if nyuyokuMember[i] >= 5 {
			seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i]) + (poolTicket[i] * poolMember[i])
			waribikiRyoukin[i] = (nyuyokuTicket[i]*5 + poolTicket[i]*poolMember[i]) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		} else if poolMember[i] >= 2 {
			seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i]) + (poolTicket[i] * poolMember[i])
			waribikiRyoukin[i] = (nyuyokuTicket[i]*5 + poolTicket[i]*poolMember[i]) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		} else {
			seikiRyoukin[i] = (nyuyokuTicket[i] * nyuyokuMember[i]) + (poolTicket[i] * poolMember[i])
			waribikiRyoukin[i] = (nyuyokuTicket[i]*5 + poolTicket[i]*2) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		}
	}

	// 各日の最も安い合計料金を出力
	for i := 0; i < n; i++ {
		fmt.Println(saiyasune[i])
	}
}

// <END-OF-CODE>
