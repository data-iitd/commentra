package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	var n int64
	var sqrt int
	var answer int
	var count int
	var i int
	var j int

	// Reading a long integer value from user input
	n, _ = strconv.ParseInt(os.Args[1], 10, 64)

	// Calculating the square root of the given number
	sqrt = int(math.Sqrt(float64(n)))

	// Initializing the answer variable to 0
	answer = 0

	// Checking for prime factors of the given number
	for i = 2; i <= sqrt; i++ {
		// Initializing a counter variable to count the number of occurrences of a prime factor
		count = 0

		// Checking if the given number is divisible by the current prime factor
		for n%i == 0 {
			n /= i
			count++
		}

		// Calculating the contribution of the current prime factor to the answer
		for j = 1; count-j >= 0; j++ {
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

