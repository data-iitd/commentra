package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	// Read the number of strings.

	cnt := make([]int64, 5)
	// Initialize the count array.

	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
		// Read each string.

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
		// Count the occurrences of each character at the start of the strings.
	}

	res := cnt[0]*cnt[1]*cnt[2] + cnt[0]*cnt[1]*cnt[3] + cnt[0]*cnt[1]*cnt[4] +
		cnt[0]*cnt[2]*cnt[3] + cnt[0]*cnt[2]*cnt[4] + cnt[0]*cnt[3]*cnt[4] +
		cnt[1]*cnt[2]*cnt[3] + cnt[1]*cnt[2]*cnt[4] + cnt[1]*cnt[3]*cnt[4] +
		cnt[2]*cnt[3]*cnt[4]
	// Calculate the number of combinations.

	fmt.Println(res)
	// Print the result.
}

// <END-OF-CODE>
