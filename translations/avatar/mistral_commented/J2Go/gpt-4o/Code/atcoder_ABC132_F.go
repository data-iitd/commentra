package main

import (
	"fmt"
)

func main() {
	mod := int64(1e9 + 7) // Assigning the value of 1e9 + 7 to a long variable named mod

	var n, k int
	fmt.Scan(&n) // Reading the first integer input and assigning it to the variable n
	fmt.Scan(&k) // Reading the second integer input and assigning it to the variable k

	len := []int{} // Creating an empty slice named len to store the lengths of subsequences
	l := 1        // Initializing the variable l to 1

	for l <= n { // Starting a while loop that runs as long as l is less than or equal to n
		r := n / (n / l) // Calculating the right end of the current subsequence
		len = append(len, r-l+1) // Adding the length of the current subsequence to the slice len
		l = r + 1 // Incrementing the variable l to consider the next subsequence
	}

	q := len(len) // Assigning the size of the slice len to the variable q
	dp := make([]int64, k*(q+1)) // Creating a slice named dp of size k * (q + 1) to store the dynamic programming results

	for j := 1; j <= q; j++ { // Starting a for loop that runs from 1 to q
		dp[j] = int64(len[j-1]) + dp[j-1] // Calculating the dp value for the current subsequence length using the previous dp value and the length of the current subsequence
	}

	for i := 1; i < k; i++ { // Starting a nested for loop that runs from 1 to k - 1 for the number of overlapping subsequences
		for j := 1; j <= q; j++ { // Starting an inner for loop that runs from 1 to q for the length of the current subsequence
			dp[i*(q+1)+j] = dp[i*(q+1)+j-1] + dp[(i-1)*(q+1)+q-j+1]*int64(len[j-1]) // Calculating the dp value for the current combination of subsequence length and number of overlapping subsequences
			dp[i*(q+1)+j] %= mod // Taking the modulo of the dp value to ensure it doesn't exceed the value of mod
		}
	}

	fmt.Println(dp[k*(q+1)-1]) // Printing the final result
}

// <END-OF-CODE>
