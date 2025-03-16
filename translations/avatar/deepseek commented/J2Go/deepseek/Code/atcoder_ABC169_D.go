package main

import (
	"fmt"
	"math"
)

func main() {
	var n int64
	fmt.Scan(&n)

	// Calculate the integer square root of n
	sqrt := int(math.Sqrt(float64(n)))

	// Initialize an answer variable to 0
	answer := 0

	// Iterate from 2 to the square root of n
	for i := 2; i <= sqrt; i++ {
		// For each number i in this range, count the number of times i divides n
		count := 0
		for n%int64(i) == 0 {
			n /= int64(i) // Update the value of n by dividing it by i
			count++
		}

		// Calculate the number of times i can be subtracted from the count
		for j := 1; count-j >= 0; j++ {
			count -= j // Update the answer variable with the number of times i can be subtracted
			answer++
		}
	}

	// If n is greater than 1 after the loop, it means n is a prime number and increments the answer by 1
	if n > 1 {
		answer++
	}

	// Print the answer
	fmt.Println(answer)
}
