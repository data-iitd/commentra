package main

import (
	"fmt"
)

var f1 [100]int
var f2 [100]int

func in() int { // Non-negative integer input
	var n int
	fmt.Scan(&n)
	return n
}

func calc(n int) { // Function to process n
	k := n % 10 // Get the last digit of n
	for n >= 10 { // While n is greater than or equal to 10
		n /= 10
	}
	f1[10*k+n]++ // Increment f1[10*k+n]
	f2[n*10+k]++ // Increment f2[n*10+k]
}

func main() {
	var N, ans int

	N = in() // Input the number
	for N > 0 { // While N is not zero
		calc(N) // Call calc function
		N-- // Decrement N
	}

	ans = 0 // Initialize answer
	for i := 0; i < 100; i++ { // Loop through f1 and f2 arrays to calculate the answer
		ans += f1[i] * f2[i]
	}
	fmt.Println(ans) // Output the answer
}
