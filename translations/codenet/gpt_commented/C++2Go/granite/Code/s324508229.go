
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	var n int
	fmt.Fscanf(reader, "%d\n", &n)

	// Initialize a 2D array to count occurrences of digit pairs
	cnt := make([][]int, 10)
	for i := 0; i < 10; i++ {
		cnt[i] = make([]int, 10)
	}

	// Count occurrences of digit pairs (first digit, last digit) for numbers from 1 to n
	for i := 1; i <= n; i++ {
		b := i % 10 // Get the last digit of the number
		a := i       // Store the original number
		for a >= 10 {
			a /= 10 // Divide by 10 until we get the first digit
		}
		cnt[a][b]++ // Increment the count for the pair (first digit, last digit)
	}

	var ans int64 // Initialize the answer variable to accumulate results

	// Calculate the total number of valid pairs by multiplying counts
	for i := 1; i <= 9; i++ { // Iterate over possible first digits
		for j := 1; j <= 9; j++ { // Iterate over possible last digits
			// Uncomment the following line for debugging to see counts
			// fmt.Printf("%d %d %d %d\n", i, j, cnt[i][j], cnt[j][i])
			ans += int64(cnt[i][j]) * int64(cnt[j][i]) // Add the product of counts for pairs (i, j) and (j, i)
		}
	}

	fmt.Println(ans) // Output the final result
}

