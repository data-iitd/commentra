package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)

	// Initialize a slice to count occurrences of each character (a-z)
	cnt := make([]int, 26)
	for i := 0; i < 26; i++ {
		cnt[i] = 1
	}

	// Read characters and count their occurrences
	s := make([]rune, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
		cnt[s[i]-'a']++
	}

	ans := int64(cnt[0])

	// Calculate the product of counts for all characters from 'b' to 'z'
	for i := 1; i < 26; i++ {
		ans *= int64(cnt[i])
		ans %= int64(1e9 + 7)
	}

	// Output the final result, subtracting 1 to exclude the empty product case
	fmt.Println(ans - 1)
}

