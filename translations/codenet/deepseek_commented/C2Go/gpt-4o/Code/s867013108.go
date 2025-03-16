package main

import (
	"fmt"
)

const DAYS = 365 // Maximum number of days

func main() {
	var n int
	var nyuyokuTicket [DAYS]int
	var poolTicket [DAYS]int
	var nyuyokuMember [DAYS]int
	var poolMember [DAYS]int
	var seikiRyoukin [DAYS]int
	var waribikiRyoukin [DAYS]int
	var saiyasune [DAYS]int

	// Read the number of days
	fmt.Scan(&n)

	// Loop through each day
	for i := 0; i < n; i++ {
		// Read the ticket prices and usage counts for the day
		fmt.Scan(&nyuyokuTicket[i], &poolTicket[i], &nyuyokuMember[i], &poolMember[i])

		// Check if the group qualifies for a discount
		if nyuyokuMember[i] >= 5 && poolMember[i] >= 2 {
			// Calculate the cost with the maximum discount
			seikiRyoukin[i] = (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]) * 8 / 10
			saiyasune[i] = seikiRyoukin[i]
		} else if nyuyokuMember[i] >= 5 {
			// Calculate the normal cost and the discounted cost if applicable
			seikiRyoukin[i] = nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			waribikiRyoukin[i] = (nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*2) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		} else if poolMember[i] >= 2 {
			// Calculate the normal cost and the discounted cost if applicable
			seikiRyoukin[i] = nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			waribikiRyoukin[i] = (nyuyokuTicket[i]*5 + poolTicket[i]*poolMember[i]) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		} else {
			// Calculate the normal cost and the discounted cost if applicable
			seikiRyoukin[i] = nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			waribikiRyoukin[i] = (nyuyokuTicket[i]*5 + poolTicket[i]*2) * 8 / 10
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		}
	}

	// Output the cheapest total cost for each day
	for i := 0; i < n; i++ {
		fmt.Println(saiyasune[i])
	}
}

// <END-OF-CODE>
