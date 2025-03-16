package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n) // Read the number of test cases

	cnt := make([]int64, 5) // Initialize a slice of size 5 to store counts

	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str) // Read a string from input

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

	res := cnt[0]*cnt[1]*cnt[2] + // Calculate the first product
		cnt[0]*cnt[1]*cnt[3] + // Calculate the second product
		cnt[0]*cnt[1]*cnt[4] + // Calculate the third product
		cnt[0]*cnt[2]*cnt[3] + // Calculate the fourth product
		cnt[0]*cnt[2]*cnt[4] + // Calculate the fifth product
		cnt[0]*cnt[3]*cnt[4] + // Calculate the sixth product
		cnt[1]*cnt[2]*cnt[3] + // Calculate the seventh product
		cnt[1]*cnt[2]*cnt[4] + // Calculate the eighth product
		cnt[1]*cnt[3]*cnt[4] + // Calculate the ninth product
		cnt[2]*cnt[3]*cnt[4]   // Calculate the tenth product

	fmt.Println(res) // Write the result to the output
}

// <END-OF-CODE>
