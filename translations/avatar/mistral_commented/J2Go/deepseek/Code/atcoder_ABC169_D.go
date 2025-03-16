package main

import (
	"fmt"
	"math"
)

func main() {
	var n int64
	fmt.Scan(&n)

	// Calculating the square root of the given number
	sqrt := int(math.Sqrt(float64(n)))

	// Initializing the answer variable to 0
	answer := 0

	// Checking for prime factors of the given number
	for i := 2; i <= sqrt; i++ {
		count := 0
		for n%int64(i) == 0 {
			n /= int64(i)
			count++
		}

		// Calculating the contribution of the current prime factor to the answer
		for j := 1; count-j >= 0; j++ {
			count -= j
			answer++
		}
	}

	// Checking for the remaining prime factor (if any)
	if n > 1 {
		answer++
	}

	// Printing the result
	fmt.Println(answer)
}

