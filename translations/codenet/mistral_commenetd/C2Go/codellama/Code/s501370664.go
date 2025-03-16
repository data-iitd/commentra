
package main

import (
	"fmt"
	"math"
)

// Declare a flag array to keep track of prime numbers
var flag []int

// Function to find prime numbers up to a given limit
func prime(num int) {
	var i, j int

	// Allocate memory for flag array of size num+1
	flag = make([]int, num+1)

	// Loop through numbers from 2 to num
	for i = 2; i*i <= num; i++ {
		// If a number is not marked as composite, mark all its multiples as composite
		if flag[i] == 0 {
			for j = 2; i*j <= num; j++ {
				flag[i*j] = 1
			}
		}
	}
}

func main() {
	var n, i, cnt int

	// Call prime function to find prime numbers up to 50000
	prime(50000)

	// Loop until user inputs 0
	for {
		// Read user input for number n
		fmt.Scan(&n)
		// Break the loop if user inputs 0
		if n == 0 {
			break
		}
		// Initialize i and cnt to 0
		i = 2
		cnt = 0
		// Loop through numbers from 2 to square root of n
		for i*i <= n {
			// If i and n-i are both prime, increment cnt
			if flag[i] == 0 && flag[n-i] == 0 {
				cnt++
			}
			// Increment i for next iteration
			i++
		}
		// Print the result
		fmt.Println(cnt)
	}

	// Return 0 to indicate successful execution
	return 0
}

