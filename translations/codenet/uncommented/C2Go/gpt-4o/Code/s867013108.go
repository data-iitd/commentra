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

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&nyuyokuTicket[i], &poolTicket[i], &nyuyokuMember[i], &poolMember[i])
		if nyuyokuMember[i] >= 5 && poolMember[i] >= 2 {
			seikiRyoukin[i] = (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]) * 8 / 10
			saiyasune[i] = seikiRyoukin[i]
		} else if nyuyokuMember[i] >= 5 {
			seikiRyoukin[i] = (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i])
			waribikiRyoukin[i] = (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*2) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		} else if poolMember[i] >= 2 {
			seikiRyoukin[i] = (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i])
			waribikiRyoukin[i] = (nyuyokuTicket[i]*5 + poolTicket[i]*poolMember[i]) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		} else {
			seikiRyoukin[i] = (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i])
			waribikiRyoukin[i] = (nyuyokuTicket[i]*5 + poolTicket[i]*2) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		}
	}
	for i := 0; i < n; i++ {
		fmt.Println(saiyasune[i])
	}
}

// <END-OF-CODE>
