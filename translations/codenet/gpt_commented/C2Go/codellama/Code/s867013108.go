package main

import (
	"fmt"
)

func main() {
	var n int // Declare variables for number of days and loop index
	var nyuyoku_ticket [365]int // Arrays to store ticket prices for each day
	var pool_ticket [365]int
	var nyuyoku_member [365]int
	var pool_member [365]int
	var seiki_ryoukin [365]int // Arrays to store calculated prices
	var waribiki_ryoukin [365]int
	var saiyasune [365]int

	fmt.Scan(&n) // Input the number of days for which prices need to be calculated
	for i := 0; i < n; i++ {
		// Input ticket prices and the number of tickets used for the current day
		fmt.Scan(&nyuyoku_ticket[i], &pool_ticket[i], &nyuyoku_member[i], &pool_member[i])

		// Check if the discount condition for both tickets is met
		if nyuyoku_member[i] >= 5 && pool_member[i] >= 2 {
			// Calculate the total price with discount
			seiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10
			saiyasune[i] = seiki_ryoukin[i] // Store the discounted price
		}
		// Check if only the nyuyoku ticket discount condition is met
		else if nyuyoku_member[i] >= 5 {
			// Calculate the total price without discount
			seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] )
			// Calculate the price with discount for pool tickets
			waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * 2 ) ) * 8 ) / 10
			// Compare and store the cheaper option
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		}
		// Check if only the pool ticket discount condition is met
		else if pool_member[i] >= 2 {
			// Calculate the total price without discount
			seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] )
			// Calculate the price with discount for nyuyoku tickets
			waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * 5 ) + ( pool_ticket[i] * pool_member[i] ) ) * 8 ) / 10
			// Compare and store the cheaper option
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		}
		// If no discount conditions are met
		else {
			// Calculate the total price without discount
			seiki_ryoukin[i] = ( nyuyoku_ticket[i] * nyuyoku_member[i] ) + ( pool_ticket[i] * pool_member[i] )
			// Calculate the price with discount for both tickets
			waribiki_ryoukin[i] = ( ( ( nyuyoku_ticket[i] * 5 ) + ( pool_ticket[i] * 2 ) ) * 8 ) / 10
			// Compare and store the cheaper option
			if seiki_ryoukin[i] >= waribiki_ryoukin[i] {
				saiyasune[i] = waribiki_ryoukin[i]
			} else {
				saiyasune[i] = seiki_ryoukin[i]
			}
		}
	}
	// Output the cheapest total price for each day
	for i := 0; i < n; i++ {
		fmt.Println(saiyasune[i])
	}
}

