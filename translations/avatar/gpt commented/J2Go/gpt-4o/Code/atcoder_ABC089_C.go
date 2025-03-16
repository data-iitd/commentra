package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize an array to count occurrences of specific starting letters
	cnt := make([]int64, 5)

	// Process each string input
	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
		// Increment the count based on the first character of the string
		switch str[0] {
		case 'M':
			cnt[0]++
		case 'A':
			cnt[1]++
		case 'R':
			cnt[2]++
		case 'C':
			cnt[3]++
		case 'H':
			cnt[4]++
		}
	}

	// Calculate the result based on combinations of counts
	res := cnt[0]*cnt[1]*cnt[2] +
		cnt[0]*cnt[1]*cnt[3] +
		cnt[0]*cnt[1]*cnt[4] +
		cnt[0]*cnt[2]*cnt[3] +
		cnt[0]*cnt[2]*cnt[4] +
		cnt[0]*cnt[3]*cnt[4] +
		cnt[1]*cnt[2]*cnt[3] +
		cnt[1]*cnt[2]*cnt[4] +
		cnt[1]*cnt[3]*cnt[4] +
		cnt[2]*cnt[3]*cnt[4]

	// Output the result
	fmt.Println(res)
}

// <END-OF-CODE>
