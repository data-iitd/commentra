package main

import (
	"fmt"
	"strconv"
)

func main() {
	var kStr, nStr, wStr string
	fmt.Scan(&kStr, &nStr, &wStr) // Taking three integers as input from the user

	k, _ := strconv.Atoi(kStr) // Convert k to integer
	n, _ := strconv.Atoi(nStr) // Convert n to integer
	w, _ := strconv.Atoi(wStr) // Convert w to integer

	if 1 <= k && w <= 1000 { // Input validation
		total := 0 // Initializing the variable 'total' to zero
		for i := 1; i <= w; i++ { // Iterating from 1 to w (inclusive)
			total += i * k // Adding the product of k and the current index to the total variable
		}

		if total > n { // Checking if the total is greater than n or not
			fmt.Println(total - n) // If yes, printing the difference between total and n
		} else {
			fmt.Println(0) // If no, printing zero
		}
	}
}

// <END-OF-CODE>
