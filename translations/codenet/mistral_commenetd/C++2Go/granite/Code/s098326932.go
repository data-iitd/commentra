
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Read the number of test cases
	var K int
	fmt.Fscan(bufio.NewReader(os.Stdin), &K)

	// Initialize the number with the minimum ratio of digits to total number
	N := f(1)

	// Print the answer for each test case
	for i := 0; i < K; i++ {
		fmt.Println(N)
		N = f(N + 1)
	}
}

func f(N int64) int64 {
	// Initialize a vector to store digits of the number
	a := make([]int64, 20)
	d := 0 // Index to store the current digit position

	// Extract digits from N and store them in the vector 'a'
	for N > 0 {
		a[d] = N % 10 // Store the current digit
		N /= 10 // Move to the next digit
		d++ // Increment the index
	}

	// Initialize minimum ratio and the result
	m := int64(1e18)
	res := N

	// Iterate through each digit position from 0 to the last digit position
	for i := 0; i <= d; i++ {
		// Initialize sum of digits before the current digit position
		bunsi := int64(0)
		// Initialize the sum of digits after the current digit position
		bunbo := int64(9 * i)

		// Calculate the sum of digits before the current digit position
		for j := d - 1; j >= 0; j-- {
			// Update the sum of digits before the current digit position
			bunsi *= 10
			if j < i {
				bunsi += 9 // Add 9 for each digit before the current digit position
			} else {
				bunsi += a[j] // Add the current digit
			}

			// Update the sum of digits after the current digit position
			if j >= i {
				bunbo += a[j]
			}
		}

		// Calculate the ratio of digits before the current digit position to the sum of digits before and after the current digit position
		frac := float64(bunsi) / float64(bunbo)

		// Update the minimum ratio and the result if the current ratio is smaller than the previous minimum ratio
		if frac < float64(m) {
			m = int64(frac)
			res = bunsi
		}
	}

	// Return the number with the minimum ratio of digits to total number
	return res
}

// 