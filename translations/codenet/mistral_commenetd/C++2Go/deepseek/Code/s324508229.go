package main

import (
	"fmt"
)

func main() {
	var n, a, b int
	fmt.Scan(&n)

	// Initialize a 10x10 2D array 'cnt' with zeroes
	cnt := [10][10]int{}

	// Iterate through each number from 1 to n
	for i := 1; i <= n; i++ {
		// Extract the last digit 'b' and the digit before last 'a' from the number 'i'
		b = i % 10
		a = i

		// While 'a' has more digits than one, extract the digit before last one
		for a >= 10 {
			a /= 10
		}

		// Increment the count of 'a'th row and 'b'th column in the 'cnt' array
		cnt[a][b]++
	}

	// Initialize answer variable 'ans' with zero
	var ans int64 = 0

	// Iterate through each row and column from 1 to 9
	for i := 1; i <= 9; i++ {
		for j := 1; j <= 9; j++ {
			// Multiply the count of 'i'th row and 'j'th column with the count of 'j'th row and 'i'th column
			// and add it to the answer
			ans += int64(cnt[i][j]) * int64(cnt[j][i])
		}
	}

	// Print the final answer
	fmt.Println(ans)
}

