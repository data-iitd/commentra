
package main

import (
	"fmt"
	"math"
)

// Function to calculate the minimum n/S(n)
func f(N int) int {
	a := make([]int, 20) // Vector to store digits of N
	d := 0               // Digit counter
	for N > 0 {
		a[d] = N % 10     // Store the last digit of N
		N /= 10           // Remove the last digit from N
		d++               // Increment the digit counter
	}
	m := math.MaxInt64   // Initialize the minimum fraction to a large number
	res := N             // Initialize the result to 0
	for i := 0; i <= d; i++ {
		bunsi := 0 // Numerator
		bunbo := 9 * i // Denominator
		for j := d - 1; j >= 0; j-- {
			bunsi *= 10
			if j < i {
				bunsi += 9 // Add 9 to the current digit if necessary
			} else {
				bunsi += a[j] // Add the actual digit
			}

			if j >= i {
				bunbo += a[j] // Add the actual digit to the denominator if necessary
			}
		}
		//fmt.Println("bb", bunsi, bunbo, "  ")
		frac := float64(bunsi) / float64(bunbo) // Calculate the fraction
		if frac < m {
			m = frac // Update the minimum fraction
			res = bunsi // Update the result
		}
	}
	return res // Return the result
}

func main() {
	var K int
	fmt.Scan(&K) // Read the number of iterations
	N := f(1)    // Initialize N with the result of f(1)
	for i := 0; i < K; i++ {
		fmt.Println(N) // Output the current N
		N = f(N + 1)   // Update N to the result of f(N+1)
	}

}

// END-OF-CODE
