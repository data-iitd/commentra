package main // Defining the main package

import (
	"fmt" // Importing the fmt package for formatted I/O
)

func main() { // Defining the main function which is the entry point of the program
	var Q, H, S, D, N int64 // Declaring variables to hold input values

	fmt.Scan(&Q) // Reading the first long value Q from the standard input
	fmt.Scan(&H) // Reading the second long value H from the standard input
	fmt.Scan(&S) // Reading the third long value S from the standard input
	fmt.Scan(&D) // Reading the fourth long value D from the standard input
	fmt.Scan(&N) // Reading the fifth long value N from the standard input

	onePrice := min(min(Q*4, H*2), S) // Calculating the minimum price per item among Q*4, H*2, and S

	if float64(onePrice) <= float64(D)/2 { // Checking if the minimum price per item is less than or equal to half of the deposit amount
		fmt.Println(N * onePrice) // If true, printing the result as the product of N and the minimum price per item
	} else { // If false, the following block is executed
		fmt.Println((N/2)*D + (N%2)*onePrice) // Calculating and printing the result as the sum of half of N multiplied by the deposit amount and the remaining N (if any) multiplied by the minimum price per item
	}
}

// min function to find the minimum of two int64 values
func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
