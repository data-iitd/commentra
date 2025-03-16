package main

import (
	"fmt"
	"math"
)

func main() {
	var n int64
	fmt.Scan(&n) // Step 1: Read a long integer n from the user

	// Step 2: Calculate the integer square root of n
	sqrt := int(math.Sqrt(float64(n)))

	// Step 3: Initialize an answer variable to 0
	answer := 0

	// Step 4: Iterate from 2 to the square root of n
	for i := 2; i <= sqrt; i++ {
		// Step 5: For each number i in this range, count the number of times i divides n
		count := 0
		for n%i == 0 {
			n /= i // Step 6: Update the value of n by dividing it by i
			count++
		}

		// Step 7: Calculate the number of times i can be subtracted from the count
		for j := 1; count-j >= 0; j++ {
			count -= j // Step 8: Update the answer variable with the number of times i can be subtracted
			answer++
		}
	}

	// Step 9: If n is greater than 1 after the loop, it means n is a prime number and increments the answer by 1
	if n > 1 {
		answer++
	}

	// Step 10: Print the answer
	fmt.Println(answer)
}

// <END-OF-CODE>
