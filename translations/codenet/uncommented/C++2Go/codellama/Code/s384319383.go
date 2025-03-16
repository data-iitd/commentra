package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	cnt := make([]int, 26)
	s := make([]byte, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&s[i])
		cnt[s[i]-'a']++
	}

	ans := cnt[0]
	for i := 1; i < 26; i++ {
		ans *= cnt[i]
		ans %= 1e9 + 7
	}

	fmt.Println(ans - 1)
}

