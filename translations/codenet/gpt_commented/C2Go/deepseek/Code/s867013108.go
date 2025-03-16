package main

import (
	"fmt"
)

const DAYS = 365 // Maximum number of days

func main() {
	var n, i int // Declare variables for number of days and loop index
	// Declare arrays to store ticket prices and the number of tickets used for each day
	nyuyokuTicket := make([]int, DAYS)
	poolTicket := make([]int, DAYS)
	nyuyokuMember := make([]int, DAYS)
	poolMember := make([]int, DAYS)
	// Declare arrays to store calculated prices
	seikiRyoukin := make([]int, DAYS)
	waribikiRyoukin := make([]int, DAYS)
	saiyasune := make([]int, DAYS)

	fmt.Scan(&n) // Input the number of days for which prices need to be calculated
	for i = 0; i < n; i++ {
		// Input ticket prices and the number of tickets used for the current day
		fmt.Scan(&nyuyokuTicket[i], &poolTicket[i], &nyuyokuMember[i], &poolMember[i])

		// Check if the discount condition for both tickets is met
		if nyuyokuMember[i] >= 5 && poolMember[i] >= 2 {
			// Calculate the total price with discount
			seikiRyoukin[i] = ((nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]) * 8) / 10
			saiyasune[i] = seikiRyoukin[i] // Store the discounted price
		} else if nyuyokuMember[i] >= 5 {
			// Calculate the total price without discount
			seikiRyoukin[i] = nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			// Calculate the price with discount for pool tickets
			waribikiRyoukin[i] = ((nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*2) * 8) / 10
			// Compare and store the cheaper option
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		} else if poolMember[i] >= 2 {
			// Calculate the total price without discount
			seikiRyoukin[i] = nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			// Calculate the price with discount for nyuyoku tickets
			waribikiRyoukin[i] = ((nyuyokuTicket[i]*5+poolTicket[i]*poolMember[i]) * 8) / 10
			// Compare and store the cheaper option
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		} else {
			// Calculate the total price without discount
			seikiRyoukin[i] = nyuyokuTicket[i]*nyuyokuMember[i] + poolTicket[i]*poolMember[i]
			// Calculate the price with discount for both tickets
			waribikiRyoukin[i] = ((nyuyokuTicket[i]*5+poolTicket[i]*2) * 8) / 10
			// Compare and store the cheaper option
			if seikiRyoukin[i] >= waribikiRyoukin[i] {
				saiyasune[i] = waribikiRyoukin[i]
			} else {
				saiyasune[i] = seikiRyoukin[i]
			}
		}
	}
	// Output the cheapest total price for each day
	for i = 0; i < n; i++ {
		fmt.Println(saiyasune[i])
	}
}
