package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	cnt := make([]int64, 5)

	for i := 0; i < n; i++ {
		var str string
		fmt.Scan(&str)
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

	fmt.Println(res)
}

// <END-OF-CODE>
