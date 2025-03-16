package main

import (
	"fmt"
)

func main() {
	// Declare variables N and D, which are integers between 1 and 20
	var N, D int // N, Dは1以上20以下の整数
	var ans, rem int // Variables to store the answer and the remainder

	// Read two integers from standard input
	fmt.Scan(&N, &D)

	// Calculate the number of complete groups of size (D*2 + 1) that can be formed from N
	ans = N / (D*2 + 1)
	// Calculate the remainder when N is divided by (D*2 + 1)
	rem = N % (D*2 + 1)

	// If there is a remainder, it means we need one additional group
	if rem != 0 {
		ans = ans + 1 // Increment the answer by 1
	}

	// Output the final answer
	fmt.Println(ans)
}

// <END-OF-CODE>
